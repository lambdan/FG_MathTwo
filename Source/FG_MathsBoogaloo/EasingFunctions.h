// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EasingFunctions.generated.h"


UENUM(BlueprintType)
enum class EEasingFunction : uint8
{
	EEF_None	UMETA(DisplayName="None"),
	EEF_SineInOut	UMETA(DisplayName="Sine In Out"),
	EEF_EaseInCirc	UMETA(DisplayName="Ease In Circ"),
	EEF_EaseInSine	UMETA(DisplayName="Ease In Sine"),
	EEF_EaseOutSine	UMETA(DisplayName="Ease Out Sine"),
	EEF_EaseInElastic	UMETA(DisplayName="Ease In Elastic"),
};

UCLASS()
class FG_MATHSBOOGALOO_API UEasingFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float Ease(const float T, const EEasingFunction EasingFunction);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float SineInOut(const float T);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float EaseInCirc(const float T);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float EaseInSine(const float T);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float EaseOutSine(const float T);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float EaseInElastic(const float T);
};
