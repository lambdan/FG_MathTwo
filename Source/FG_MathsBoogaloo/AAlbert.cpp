// Fill out your copyright notice in the Description page of Project Settings.


#include "AAlbert.h"

// Sets default values
AAAlbert::AAAlbert()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool AAAlbert::ShouldTickIfViewportsOnly() const
{
	// return Super::ShouldTickIfViewportsOnly();
	return true;
}

// Called when the game starts or when spawned
void AAAlbert::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAAlbert::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
	// GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Green, TEXT("Hello"));
}

