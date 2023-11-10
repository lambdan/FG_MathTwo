// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EasingFunctions.generated.h"


UENUM(BlueprintType)
enum class EEasingFunction : uint8
{
	EEF_None UMETA(DisplayName="None"),
	EEF_easeInSine UMETA(DisplayName="easeInSine"),
	EEF_easeOutSine UMETA(DisplayName="easeOutSine"),
	EEF_easeInOutSine UMETA(DisplayName="easeInOutSine"),
	EEF_easeInQuad UMETA(DisplayName="easeInQuad"),
	EEF_easeOutQuad UMETA(DisplayName="easeOutQuad"),
	EEF_easeInOutQuad UMETA(DisplayName="easeInOutQuad"),
	EEF_easeInCubic UMETA(DisplayName="easeInCubic"),
	EEF_easeOutCubic UMETA(DisplayName="easeOutCubic"),
	EEF_easeInOutCubic UMETA(DisplayName="easeInOutCubic"),
	EEF_easeInQuart UMETA(DisplayName="easeInQuart"),
	EEF_easeOutQuart UMETA(DisplayName="easeOutQuart"),
	EEF_easeInOutQuart UMETA(DisplayName="easeInOutQuart"),
	EEF_easeInQuint UMETA(DisplayName="easeInQuint"),
	EEF_easeOutQuint UMETA(DisplayName="easeOutQuint"),
	EEF_easeInOutQuint UMETA(DisplayName="easeInOutQuint"),
	EEF_easeInExpo UMETA(DisplayName="easeInExpo"),
	EEF_easeOutExpo UMETA(DisplayName="easeOutExpo"), 
	EEF_easeInOutExpo UMETA(DisplayName="easeInOutExpo"),
	EEF_easeInCirc UMETA(DisplayName="easeInCirc"),
	EEF_easeOutCirc UMETA(DisplayName="easeOutCirc"),
	EEF_easeInOutCirc UMETA(DisplayName="easeInOutCirc"),
	EEF_easeInBack UMETA(DisplayName="easeInBack"),
	EEF_easeOutBack UMETA(DisplayName="easeOutBack"),
	EEF_easeInOutBack UMETA(DisplayName="easeInOutBack"),
	EEF_easeInElastic UMETA(DisplayName="easeInElastic"),
	EEF_easeOutElastic UMETA(DisplayName="easeOutElastic"),
	EEF_easeInOutElastic UMETA(DisplayName="easeInOutElastic"),
	EEF_easeInBounce UMETA(DisplayName="easeInBounce"),
	EEF_easeOutBounce UMETA(DisplayName="easeOutBounce"),
	EEF_easeInOutBounce UMETA(DisplayName="easeInOutBounce"),
};

UCLASS()
class FG_MATHSBOOGALOO_API UEasingFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float Ease(const float T, const EEasingFunction EasingFunction);


	// could wrap all of these in UFUNCTION(BlueprintCallable...) but makes it so messy here. we can just use the function above from Blueprints instead

	static float easeInSine(const float x);
	static float easeOutSine(const float x);
	static float easeInOutSine(const float x);
	static float easeInQuad(const float x);
	static float easeOutQuad(const float x);
	static float easeInOutQuad(const float x);
	static float easeInCubic(const float x);
	static float easeOutCubic(const float x);
	static float easeInOutCubic(const float x);
	static float easeInQuart(const float x);
	static float easeOutQuart(const float x);
	static float easeInOutQuart(const float x);
	static float easeInQuint(const float x);
	static float easeOutQuint(const float x);
	static float easeInOutQuint(const float x);
	static float easeInExpo(const float x);
	static float easeOutExpo(const float x);
	static float easeInOutExpo(const float x);
	static float easeInCirc(const float x);
	static float easeOutCirc(const float x);
	static float easeInOutCirc(const float x);
	static float easeInBack(const float x);
	static float easeOutBack(const float x);
	static float easeInOutBack(const float x);
	static float easeInElastic(const float x);
	static float easeOutElastic(const float x);
	static float easeInOutElastic(const float x);
	static float easeInBounce(const float x);
	static float easeOutBounce(const float x);
	static float easeInOutBounce(const float x);
};
