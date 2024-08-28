// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Default_Default.h"
#include "../Battlecry.h"
#include "RTSGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAI_Default_Default::AAI_Default_Default()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_Default_Default::BeginPlay()
{
	Super::BeginPlay();
	ARTSGameMode* GameMode = Cast<ARTSGameMode>(UGameplayStatics::GetGameMode(this));
	GameMode->DefDefLeft++;
}

// Called every frame
void AAI_Default_Default::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Default_Default::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

