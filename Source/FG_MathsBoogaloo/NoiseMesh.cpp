// 5: Noise
// if i made this file today i would've called it FlyingCarpet

#include "NoiseMesh.h"


// Sets default values
ANoiseMesh::ANoiseMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProceduralMeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>("Procedural Mesh");
	ProceduralMeshComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ANoiseMesh::BeginPlay()
{
	PlayerPawn = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawnOrSpectator();
	SpawnTransform = GetActorTransform();
	
	Super::BeginPlay();
	Initialize();
}

// Called every frame
void ANoiseMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerPawn != nullptr)
	{
		// should probably use intersection but its a little glitchy since the mesh moves around

		// TODO maybe switch to rayplane (check if rug is underneath player)
		
		float DistanceToPlayer = FVector::Distance(this->GetActorLocation(), PlayerPawn->GetActorLocation());

		// UE_LOG(LogTemp, Warning, TEXT("%f"), DistanceToPlayer);
		if (DistanceToPlayer < 300)
		{
			PlayerOnMe = true;
			AddActorWorldOffset(PlayerPawn->GetActorForwardVector() * MovementSpeed * DeltaTime);
			Initialize();
		}
		else if (PlayerOnMe)
		{
			// player fell off, return to spawn
			SetActorTransform(SpawnTransform);
			PlayerOnMe = false;
		} else if (DistanceToPlayer < 1000) // only "animate" when player is close to it
		{
			AddActorWorldOffset(PlayerPawn->GetActorForwardVector() * IdleSpeed * DeltaTime);
			Initialize();
		}
	}
}

void ANoiseMesh::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	Initialize();
}


void ANoiseMesh::Initialize()
{
	GenerateNoise();
	GenerateMesh();

	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertis, Triangles, UVs, Norms, Tangents);

	ProceduralMeshComponent->CreateMeshSection(0, Vertis, Triangles, Norms, UVs, Colors, Tangents, Collision);
	ProceduralMeshComponent->SetMaterial(0, Mat);
}

void ANoiseMesh::GenerateNoise()
{
	Resolution = FMath::Max(1, Resolution); // prevent 0 resolution (crashes)
	Resolution = FMath::Min(256, Resolution); // gets super unresponsive around 300
	Offset = FVector2D(GetActorLocation().X, GetActorLocation().Y); // makes it look wavy when moving, like a flying carpet

	NoiseArray.SetNum((Resolution+1) * (Resolution+1));

	for(int y = 0; y <= Resolution; y++)
	{
		for(int x = 0; x <= Resolution; x++)
		{
			FVector2D pos = FVector2D(
				(x + Offset.X) * Scale,
				(y + Offset.Y) * Scale
				);

			const int32 i = y * Resolution + x;
			
			NoiseArray[i] = FMath::PerlinNoise2D(pos) * Strength;// * FMath::RandRange(0.0f, 1.0f); // tried giving it a random value here, which kinda worked but destroyed the smoothness
			
		}
	}
}

void ANoiseMesh::GenerateMesh()
{
	Vertis.SetNum(NoiseArray.Num());
	Triangles.SetNum(Resolution*Resolution*6); // why * 6? because you only get "half squares" otherwise (like a diagonally cut sandwich)
	Colors.SetNum(NoiseArray.Num());
	Norms.SetNum(NoiseArray.Num());
	UVs.SetNum(NoiseArray.Num());

	float stepSize = 1.0f / Resolution;

	// int v = 0;
	for(int v = 0, y = 0; y <= Resolution; y++)
	{
		for(int x = 0; x <= Resolution; x++, v++)
		{
			int i = y * Resolution + x;
			float noise = NoiseArray[i];
			// UE_LOG(LogTemp, Warning, TEXT("%f"), noise);
			// int v = (y*x) + x;
			Vertis[v] = FVector((x * stepSize - 0.5f), (y * stepSize - 0.5f), noise) * MeshScale;
			UVs[v] = FVector2D(x * stepSize, y * stepSize);
		}
	}

	for(int t = 0, v = 0, y = 0; y < Resolution; y++, v++)
	{
		for(int x = 0; x < Resolution; x++, v++, t += 6)
		{
			Triangles[t] = v;
			Triangles[t+1] = v + Resolution + 1;
			Triangles[t+2] = v + 1;

			Triangles[t+3] = v + Resolution + 1;
			Triangles[t+4] = v + Resolution + 2;
			Triangles[t+5] = v + 1;
		}
	}

	CalculateNormals();
	
}

void ANoiseMesh::CalculateNormals()
{
	for(int v = 0, y = 0; y <= Resolution; y++)
	{
		for(int x = 0; x <= Resolution; x++, v++)
		{
			FVector n = FVector::UpVector;
			n.Z = FMath::Square(1.0 - (n.X * n.X + n.Y * n.Y));
			Norms[v] = n;
		}
	}
}

