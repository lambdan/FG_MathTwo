// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AAlbert.generated.h"

UCLASS()
class FG_MATHSBOOGALOO_API AAAlbert : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAAlbert();

	virtual bool ShouldTickIfViewportsOnly() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TArray<AActor*> TestActors;

	// How close something needs to be for us to check for it
	UPROPERTY(EditAnywhere)
	float CheckDistance = 1000;
	
	UFUNCTION(BlueprintCallable,BlueprintPure)
	bool IsInFrontOfUs(AActor* OtherActor);
	bool IsBehindUs(AActor* OtherActor);
	bool IsBelowUs(AActor* OtherActor);
	bool IsAboveUs(AActor* OtherActor);
};
