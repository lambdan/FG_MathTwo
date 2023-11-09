// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IntersectionLibrary.generated.h"


UENUM(BlueprintType)
enum EIntersection
{
	Plane,
	Sphere,
	Triangle,
	AABB,
	Ray,
};


UCLASS()
class FG_MATHSBOOGALOO_API UIntersectionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// Returns true if Actor A and B is intersecting with each other (using AABB)
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool AABBIntersection(AActor* ActorA, AActor* ActorB);
	
};
