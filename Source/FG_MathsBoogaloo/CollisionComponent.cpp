// 4: Collision

#include "CollisionComponent.h"
#include "IntersectionLibrary.h"
#include "VectorUtil.h"
#include "Kismet/GameplayStatics.h"

UCollisionComponent::UCollisionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UCollisionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCollisionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("COLLISION"), CollisionActors); // get all actors with the COLLISION tag (we'll check for collision against these fellas)

	bool InAir = true;
	for (auto& B : CollisionActors)
	{
		if (B == GetOwner()) // dont collide with ourselves
		{
			continue;
		}

		// try to get collision component of other actor to best determine what kind of intersection to test for
		int TestIntersection = 0; // 0 = AABB-AABB, 1 = Sphere-Actor, 2 = Sphere-Sphere
		UCollisionComponent* BCC = Cast<UCollisionComponent>(B->GetComponentByClass(UCollisionComponent::StaticClass()));
		if (BCC == nullptr)
		{
			// AABB-AABB as default
			TestIntersection = 0;
		}
		else if (BCC->IntersectionShape == EIntersectionShape::EIS_Sphere && IntersectionShape == EIntersectionShape::EIS_Sphere)
		{
			// both are spheres
			TestIntersection = 2;
		}
		else if (IntersectionShape == EIntersectionShape::EIS_Sphere || BCC->IntersectionShape == EIntersectionShape::EIS_Sphere)
		{
			// one of them is a sphere
			TestIntersection = 1;
		}

		if (TestIntersection == 0) // AABB
		{
			if (UIntersectionLibrary::AABBIntersection(GetOwner(), B))
			{
				InAir = false;
				auto OurLocation = GetOwner()->GetActorLocation();
				auto ClosestPointOnOtherActor = B->GetComponentsBoundingBox().GetClosestPointTo(OurLocation);
				auto HitNormal = (GetOwner()->GetActorLocation() - ClosestPointOnOtherActor).GetSafeNormal();
				DrawDebugDirectionalArrow(GetWorld(), ClosestPointOnOtherActor, ClosestPointOnOtherActor + (HitNormal * 100), 1000, FColor::Blue, false, 2);
				Velocity = FMath::Max(Velocity.Length(), 100) * HitNormal * 0.8f;
			}
		}
		else if (TestIntersection == 1) // Sphere to actor
		{
			FVector ALoc = GetOwner()->GetActorLocation();
			float ARadius = GetOwner()->GetActorScale3D().X;

			if (UIntersectionLibrary::SphereActorIntersecting(ALoc, ARadius, B))
			{
				InAir = false;
				auto OurLocation = GetOwner()->GetActorLocation();
				auto ClosestPointOnOtherActor = B->GetComponentsBoundingBox().GetClosestPointTo(OurLocation);
				auto HitNormal = (GetOwner()->GetActorLocation() - ClosestPointOnOtherActor).GetSafeNormal();
				DrawDebugDirectionalArrow(GetWorld(), ClosestPointOnOtherActor, ClosestPointOnOtherActor + (HitNormal * 100), 1000, FColor::Green, false, 2);
				Velocity = FMath::Max(Velocity.Length(), 100) * HitNormal * 0.8f;
			}
		}
		else if (TestIntersection == 2)
		{
			FVector ALoc = GetOwner()->GetActorLocation();
			float ARadius = GetOwner()->GetActorScale3D().X;
			FVector BLoc = B->GetActorLocation();
			float BRadius = B->GetActorScale3D().X;

			if (UIntersectionLibrary::SphereSphereIntersection(ALoc, ARadius, BLoc, BRadius))
			{
				// InAir = false;
				FVector Normal = (ALoc - BLoc).GetSafeNormal();
				FVector ImpactPoint = ALoc + (Normal * ARadius);
				DrawDebugSphere(GetWorld(), ImpactPoint, 5, 5, FColor::Red, false, 1);
				DrawDebugDirectionalArrow(GetWorld(), ImpactPoint, ImpactPoint + (Normal * 100), 1000, FColor::Magenta, false, 1);
				Velocity = Velocity.Length() * Normal;
			}
		}
	}

	if (InAir && UseGravity)
	{
		Velocity += GravityConstant * Mass * DeltaTime;
	}

	GetOwner()->AddActorWorldOffset(Velocity * DeltaTime);
}

void UCollisionComponent::AddForce(FVector ForceToAdd)
{
	Velocity += ForceToAdd;
}
