// 3: Intersection

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IntersectionLibrary.generated.h"

UCLASS()
class FG_MATHSBOOGALOO_API UIntersectionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// Returns true if Actor A and B is intersecting
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool AABBIntersection(AActor* ActorA, AActor* ActorB);

	// Returns true if Box A and Box B intersects
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool AABBIntersectionBoxes(FBox BoxA, FBox BoxB);

	// Returns true if Sphere A is intersecting with actor B
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool SphereActorIntersecting(FVector SphereALocation, float SphereARadius, AActor* ActorB);

	// Returns true if spheres A and B are intersecting
	static bool SphereSphereIntersection(FVector SphereALocation, float SphereARadius, FVector SphereBLocation, float SphereBRadius);
};
