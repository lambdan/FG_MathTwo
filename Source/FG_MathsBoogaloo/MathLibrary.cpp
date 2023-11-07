// Fill out your copyright notice in the Description page of Project Settings.


#include "MathLibrary.h"

bool UMathLibrary::IsInFront(AActor* ActorA, AActor* ActorB, float Tolerance)
{
	if(ActorA == nullptr || ActorB == nullptr)
	{
		return false;
	}
	
	auto LocationA = ActorA->GetActorLocation();
	auto LocationB = ActorB->GetActorLocation();
	
	auto Direction = (LocationB - LocationA).GetSafeNormal();
	auto dot = FVector::DotProduct(Direction, ActorA->GetActorForwardVector());
	
	if (dot > Tolerance)
	{
		return true;
	}

	return false;
}

bool UMathLibrary::IsBehind(AActor* ActorA, AActor* ActorB, float Tolerance)
{
	if(ActorA == nullptr || ActorB == nullptr)
	{
		return false;
	}
	
	auto LocationA = ActorA->GetActorLocation();
	auto LocationB = ActorB->GetActorLocation();
	
	auto Direction = (LocationB - LocationA).GetSafeNormal();
	auto dot = FVector::DotProduct(Direction, ActorA->GetActorForwardVector());

	// UE_LOG(LogTemp, Warning, TEXT("%f"), dot);
	
	if (dot < -Tolerance)
	{
		return true;
	}

	return false;	
}


/*
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
*/