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

	
	for(int i = 0; i < TestActors.Num(); i++)
	{
		if(TestActors[i] == nullptr)
		{
			continue;
		}
		
		auto Distance = FVector::Distance(GetActorLocation(), TestActors[i]->GetActorLocation());

		if(Distance > CheckDistance)
		{
			continue;
		}

		auto OtherActor = TestActors[i];
		UE_LOG(LogTemp, Warning, TEXT("%s in front of us: %s"), *OtherActor->GetActorNameOrLabel(), IsInFrontOfUs(OtherActor) ? TEXT("True") : TEXT("False"));
		UE_LOG(LogTemp, Warning, TEXT("%s behind us: %s"), *OtherActor->GetActorNameOrLabel(), IsBehindUs(OtherActor) ? TEXT("True") : TEXT("False"));
		UE_LOG(LogTemp, Warning, TEXT("%s above us: %s"), *OtherActor->GetActorNameOrLabel(), IsAboveUs(OtherActor) ? TEXT("True") : TEXT("False"));
		UE_LOG(LogTemp, Warning, TEXT("%s below us: %s"), *OtherActor->GetActorNameOrLabel(), IsBelowUs(OtherActor) ? TEXT("True") : TEXT("False"));
	}
	
}

bool AAAlbert::IsInFrontOfUs(AActor* OtherActor)
{
	auto OurLocation = GetActorLocation();
	auto directionA = (OtherActor->GetActorLocation() - OurLocation).GetSafeNormal();
	auto dot = FVector::DotProduct(directionA, GetActorForwardVector());
	// UE_LOG(LogTemp, Warning, TEXT("dot %s = %f"), *OtherActor->GetActorNameOrLabel(), dot);
	if (dot > 0.9)
	{
		return true;
	}

	return false;
}

bool AAAlbert::IsBehindUs(AActor* OtherActor)
{
	auto OurLocation = GetActorLocation();
	auto directionA = (OtherActor->GetActorLocation() - OurLocation).GetSafeNormal();
	auto dot = FVector::DotProduct(directionA, GetActorForwardVector());
	if (dot < -0.9)
	{
		return true;
	}

	return false;
}

bool AAAlbert::IsBelowUs(AActor* OtherActor)
{
	auto OurLocation = GetActorLocation();
	auto directionA = (OtherActor->GetActorLocation() - OurLocation).GetSafeNormal();
	auto dot = FVector::DotProduct(directionA, GetActorUpVector());
	if (dot < 0)
	{
		return true;
	}

	return false;	
}

bool AAAlbert::IsAboveUs(AActor* OtherActor)
{
	auto OurLocation = GetActorLocation();
	auto directionA = (OtherActor->GetActorLocation() - OurLocation).GetSafeNormal();
	auto dot = FVector::DotProduct(directionA, GetActorUpVector());
	if (dot > 0)
	{
		return true;
	}

	return false;		
}
