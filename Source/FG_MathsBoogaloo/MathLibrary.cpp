// Fill out your copyright notice in the Description page of Project Settings.


#include "MathLibrary.h"

bool UMathLibrary::IsInFront(AActor* ActorA, AActor* ActorB, float Tolerance, float Distance)
{
	if(ActorA == nullptr || ActorB == nullptr)
	{
		return false;
	}
	
	auto LocationA = ActorA->GetActorLocation();
	auto LocationB = ActorB->GetActorLocation();

	auto d = FVector::Distance(LocationA, LocationB);
	// UE_LOG(LogTemp, Warning, TEXT("distance = %f"), d);
	if(d > Distance)
	{
		return false;
	}
	
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

bool UMathLibrary::IsAbove(AActor* ActorA, AActor* ActorB, float Tolerance)
{
	if(ActorA == nullptr || ActorB == nullptr)
	{
		return false;
	}
	
	auto LocationA = ActorA->GetActorLocation();
	auto LocationB = ActorB->GetActorLocation();
	auto Direction = (LocationB - LocationA).GetSafeNormal();
	
	auto dot = FVector::DotProduct(Direction, ActorA->GetActorUpVector());

	// UE_LOG(LogTemp, Warning, TEXT("%f"), dot);
	
	if (dot > Tolerance)
	{
		return true;
	}

	return false;	
}

bool UMathLibrary::IsBelow(AActor* ActorA, AActor* ActorB, float Tolerance)
{
	if(ActorA == nullptr || ActorB == nullptr)
	{
		return false;
	}
	
	auto LocationA = ActorA->GetActorLocation();
	auto LocationB = ActorB->GetActorLocation();
	auto Direction = (LocationB - LocationA).GetSafeNormal();
	
	auto dot = FVector::DotProduct(Direction, ActorA->GetActorUpVector());

	// UE_LOG(LogTemp, Warning, TEXT("%f"), dot);
	
	if (dot < -Tolerance)
	{
		return true;
	}

	return false;	
}

bool UMathLibrary::IsFaster(AActor* ActorA, AActor* ActorB)
{
	if (ActorA == nullptr || ActorB == nullptr)
	{
		return false;
	}

	auto VelocityA = ActorA->GetVelocity();
	auto VelocityB = ActorB->GetVelocity();
	auto SpeedA = VelocityA.Size();
	auto SpeedB = VelocityB.Size();

	UE_LOG(LogTemp, Warning, TEXT("Actor A speed %f"), SpeedA);
	UE_LOG(LogTemp, Warning, TEXT("Actor B speed %f"), SpeedB);

	return SpeedB > SpeedA;
}
