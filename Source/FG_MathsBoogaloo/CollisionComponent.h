// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CollisionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FG_MATHSBOOGALOO_API UCollisionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCollisionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY()
	TArray<AActor*> CollisionActors;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Mass = 10;

	UFUNCTION(BlueprintCallable)
	void AddForce(const FVector Force);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool UseGravity = true;

	UPROPERTY()
	FVector Acc;

	UPROPERTY()
	FVector Velocity;
};
