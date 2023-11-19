// 4: Collision

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CollisionComponent.generated.h"


UENUM(BlueprintType)
enum class EIntersectionShape : uint8
{
	EIS_Default	UMETA(DisplayNam="Default"),
	EIS_Sphere	UMETA(DisplayName="Sphere"),
};

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

// private:
// 	bool Colliding = false;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY()
	TArray<AActor*> CollisionActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector GravityConstant = FVector(0,0,-9.8);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Mass = 10;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EIntersectionShape IntersectionShape = EIntersectionShape::EIS_Default;
	

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool UseGravity = true;



	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	FVector Velocity;

	UFUNCTION(BlueprintCallable)
	void AddForce(FVector ForceToAdd);
	
};
