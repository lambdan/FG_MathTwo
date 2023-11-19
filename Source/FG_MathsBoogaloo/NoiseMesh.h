// 5: Noise
// if i made this file today i would've called it FlyingCarpet

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "KismetProceduralMeshLibrary.h"
#include "NoiseMesh.generated.h"


UCLASS()
class FG_MATHSBOOGALOO_API ANoiseMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANoiseMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	APawn* PlayerPawn;
	FTransform SpawnTransform;
	bool PlayerOnMe = false;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere)
	UProceduralMeshComponent* ProceduralMeshComponent;

	UPROPERTY(EditAnywhere)
	FVector MeshScale = FVector(1000, 1000, 100);

	UPROPERTY(EditAnywhere)
	FVector2D Offset;

	UPROPERTY(EditAnywhere)
	int32 Resolution = 32;

	UPROPERTY(EditAnywhere)
	float Scale = 0.01f;

	UPROPERTY(EditAnywhere)
	float Strength = 10;
	
	UPROPERTY(EditAnywhere)
	bool Collision = true;
	
	UPROPERTY(EditAnywhere)
	UMaterialInterface* Mat;

	UPROPERTY(EditAnywhere)
	float MovementSpeed = 100;

	UPROPERTY(EditAnywhere)
	float IdleSpeed = 5;


	TArray<float> NoiseArray;
	TArray<FVector> Vertis;
	TArray<FVector> Norms;
	TArray<FVector2D> UVs;
	TArray<int32> Triangles;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> Colors;

	UFUNCTION(BlueprintCallable)
	void Initialize();

	UFUNCTION(BlueprintCallable)
	void GenerateNoise();

	UFUNCTION(BlueprintCallable)
	void GenerateMesh();

	void CalculateNormals();
	
};
