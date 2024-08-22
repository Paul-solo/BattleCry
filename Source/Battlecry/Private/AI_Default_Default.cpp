// Fill out your copyright notice in the Description page of Project Settings.

#include "../Battlecry.h"
#include "AI_Default_Default.h"

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
	//UGameplayStatic::GetGameMode();
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

