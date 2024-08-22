// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "NavigationSystem.h"
#include "AI/NavigationSystemBase.h"
// Sets default values
ASpawner::ASpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASpawner::Spawn(int Wave)
{
	if (GetWorld() == nullptr)
	{
		return;
	}

	int NumberOfSpawnsForThisSpawn = (Wave + 1) / int(EnemyType);

	if (NumberOfSpawnsForThisSpawn > MaxSpawns)
	{
		IsDecreasing = true;
	}

	if (IsDecreasing == true)
	{
		NumberOfSpawnsForThisSpawn = Wave - ((Wave / 3));
	}

	for (int i = 0; i < NumberOfSpawnsForThisSpawn; i++)
	{
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		FVector Result;
		bool bSuccess = NavSys->K2_GetRandomReachablePointInRadius(GetWorld(), GetActorLocation(), Result, 600);

		GetWorld()->SpawnActor<AActor>(EnemyClass, Result, FRotator::ZeroRotator, ActorSpawnParams);
	}
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (!NavSys)
	{
		return;
	}
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

