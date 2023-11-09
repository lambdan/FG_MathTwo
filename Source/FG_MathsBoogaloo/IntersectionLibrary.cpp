// Fill out your copyright notice in the Description page of Project Settings.


#include "IntersectionLibrary.h"

bool UIntersectionLibrary::AABBIntersection(AActor* ActorA, AActor* ActorB)
{
	if(ActorA == nullptr || ActorB == nullptr)
	{
		return false;
	}
	
	auto boundingBoxA = ActorA->GetComponentsBoundingBox();
	auto boundingBoxB = ActorB->GetComponentsBoundingBox();

	if
	(
		boundingBoxA.Min.X <= boundingBoxB.Max.X && boundingBoxA.Max.X >= boundingBoxB.Min.X &&
		boundingBoxA.Min.Y <= boundingBoxB.Max.Y && boundingBoxA.Max.Y >= boundingBoxB.Min.Y &&
		boundingBoxA.Min.Z <= boundingBoxB.Max.Z && boundingBoxA.Max.Z >= boundingBoxB.Min.Z
	)
	{
		return true;
	}
	
	return false;
}
