

#include "CollisionComponent.h"

#include "IntersectionLibrary.h"
#include "Kismet/GameplayStatics.h"


UCollisionComponent::UCollisionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UCollisionComponent::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("COLLISION"), CollisionActors);
}

void UCollisionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(UseGravity)
	{
		Acc = FVector(0,0,-0.98 * Mass);
	}
	
	for(auto & B : CollisionActors)
	{
		if(B == GetOwner()) // ignore ourselves
		{ 
			continue;
		}

		// UE_LOG(LogTemp, Warning, TEXT("%s"), *B->GetActorNameOrLabel());
		
		if(UIntersectionLibrary::AABBIntersection(GetOwner(), B))
		{
			
			AddForce(-Velocity * 2);
			// UE_LOG(LogTemp, Warning, TEXT("%f %f %f"), Acc.X, Acc.Y, Acc.Z);
		}
	}
	
	Velocity += Acc;
	GetOwner()->AddActorWorldOffset(Velocity * DeltaTime);
	Acc = FVector(0, 0, 0);
}

void UCollisionComponent::AddForce(const FVector Force)
{
	Acc += Force;
}

