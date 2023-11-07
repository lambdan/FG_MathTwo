// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathLibrary.generated.h"

/**
 * 
 */
UCLASS()
class FG_MATHSBOOGALOO_API UMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// Returns true if Actor B is in front of Actor A. Tolerance closer to 1 means you have to be straight ahead.
	UFUNCTION(BlueprintCallable,BlueprintPure)
	static bool IsInFront(AActor* ActorA, AActor* ActorB, float Tolerance=0.9);

	// Returns true if Actor B is behind Actor A. Tolerance closer to 1 means you have to be almost perfectly straight behind enemy.
	UFUNCTION(BlueprintCallable,BlueprintPure)
	static bool IsBehind(AActor* ActorA, AActor* ActorB, float Tolerance=0.5);
	
	// static bool IsBelowUs(AActor* OtherActor);
	// static bool IsAboveUs(AActor* OtherActor);
	
};
