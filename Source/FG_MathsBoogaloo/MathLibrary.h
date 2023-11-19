// 1: State and Context

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathLibrary.generated.h"


UCLASS()
class FG_MATHSBOOGALOO_API UMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// Returns true if Actor B is in front of Actor A. Tolerance closer to 1 means you have to be straight ahead.
	UFUNCTION(BlueprintCallable,BlueprintPure)
	static bool IsInFront(AActor* ActorA, AActor* ActorB, float Tolerance=0.9, float Distance=1000);

	// Returns true if Actor B is behind Actor A. Tolerance closer to 1 means you have to be almost perfectly straight behind enemy.
	UFUNCTION(BlueprintCallable,BlueprintPure)
	static bool IsBehind(AActor* ActorA, AActor* ActorB, float Tolerance=0.5, float Distance=150);
	
	// Returns true if Actor B is above Actor A. Tolerance closer to 1 means Actor A have to be more centered under Actor B.
	UFUNCTION(BlueprintCallable,BlueprintPure)
	static bool IsAbove(AActor* ActorA, AActor* ActorB, float Tolerance=0.9);
	
	// Returns true if Actor B is below Actor A. Tolerance closer to 1 means Actor A have to be more centered above Actor B.
	UFUNCTION(BlueprintCallable,BlueprintPure)
	static bool IsBelow(AActor* ActorA, AActor* ActorB, float Tolerance=0.7);

	// Returns true if Actor B is moving faster than Actor A
	UFUNCTION(BlueprintCallable,BlueprintPure)
	static bool IsFaster(AActor* ActorA, AActor* ActorB);
};
