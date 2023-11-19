// 3: Intersection

#include "IntersectionLibrary.h"

bool UIntersectionLibrary::AABBIntersection(AActor* ActorA, AActor* ActorB)
{
	if(ActorA == nullptr || ActorB == nullptr)
	{
		return false;
	}
	
	auto boundingBoxA = ActorA->GetComponentsBoundingBox();
	auto boundingBoxB = ActorB->GetComponentsBoundingBox();
	
	if
	(
		boundingBoxA.Min.X <= boundingBoxB.Max.X && boundingBoxA.Max.X >= boundingBoxB.Min.X &&
		boundingBoxA.Min.Y <= boundingBoxB.Max.Y && boundingBoxA.Max.Y >= boundingBoxB.Min.Y &&
		boundingBoxA.Min.Z <= boundingBoxB.Max.Z && boundingBoxA.Max.Z >= boundingBoxB.Min.Z
	)
	{
		// UE_LOG(LogTemp, Warning, TEXT("%s AABBing with %s"), *ActorA->GetActorNameOrLabel(), *ActorB->GetActorNameOrLabel());
		return true;
	}

	return false;
	
}

bool UIntersectionLibrary::AABBIntersectionBoxes(FBox BoxA, FBox BoxB)
{
	auto boundingBoxA = BoxA;
	auto boundingBoxB = BoxB;
	if
	(
		boundingBoxA.Min.X <= boundingBoxB.Max.X && boundingBoxA.Max.X >= boundingBoxB.Min.X &&
		boundingBoxA.Min.Y <= boundingBoxB.Max.Y && boundingBoxA.Max.Y >= boundingBoxB.Min.Y &&
		boundingBoxA.Min.Z <= boundingBoxB.Max.Z && boundingBoxA.Max.Z >= boundingBoxB.Min.Z
	)
	{
		// UE_LOG(LogTemp, Warning, TEXT("%s AABBing with %s"), *ActorA->GetActorNameOrLabel(), *ActorB->GetActorNameOrLabel());
		return true;
	}

	return false;
	
}


/*
 * Ye who might be reading this:
 * 
 * multiplying the radiuses by 50 might seem arbitrary but its because we pass in the Actor Scale, the Actor Scale X to be precise.
 * since scale (1.0, 1.0, 1.0) is a sphere that is 100 cm, we multiply it by 50 to get the radius (we could also do InRadius * 100 * 0.5f) 
 */

bool UIntersectionLibrary::SphereActorIntersecting(FVector SphereALocation, float SphereARadius, AActor* ActorB)
{
	FVector ClosestPointOnB = ActorB->GetComponentsBoundingBox().GetClosestPointTo(SphereALocation);

	// DrawDebugSphere(ActorB->GetWorld(), ClosestPointOnB, 5, 5, FColor::Red, false, 0.1f);
	
	float Distance = FVector::Distance(ClosestPointOnB, SphereALocation);
	return Distance < (SphereARadius * 50);
}

bool UIntersectionLibrary::SphereSphereIntersection(FVector SphereALocation, float SphereARadius, FVector SphereBLocation, float SphereBRadius)
{
	// https://studiofreya.com/3d-math-and-physics/simple-sphere-sphere-collision-detection-and-collision-response/
	
	float SumRadius = (SphereARadius * 50) + (SphereBRadius * 50);
	float Distance = FVector::Distance(SphereALocation, SphereBLocation);
	return SumRadius > Distance;

}