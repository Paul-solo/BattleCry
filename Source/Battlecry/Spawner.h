#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UENUM()
enum class EEnemyType : uint8
{
    EET_Zombie = 1,
    EET_Skeletol = 3,
    EET_Tank = 6
};

UCLASS()
class ROBOPOPE_API ASpawner : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ASpawner();

    UFUNCTION(BlueprintCallable)
    void Spawn(int Wave);

    UPROPERTY(EditAnywhere)
    TSubclassOf<class AActor> EnemyClass;

    UPROPERTY(EditAnywhere)
    EEnemyType EnemyType = EEnemyType::EET_Zombie;

    UPROPERTY(EditAnywhere)
    int MaxSpawns = 55;

    bool IsDecreasing = false;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
    class UNavigationSystemV1* NavSys;
};