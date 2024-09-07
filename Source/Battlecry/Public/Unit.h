// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIData.h"
#include "GameFramework/Character.h"
#include "Unit.generated.h"

UCLASS()
class BATTLECRY_API AUnit : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AUnit();

	bool isSelected = false;

	int State = States::STANDING;
	int ActionState = ActionStates::WAITING;

	void MoveToLocation(FVector Location);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Selected Plane")
	UStaticMeshComponent* SelectedPlane;

	UPROPERTY(EditDefaultsOnly)
	float SelectedPlaneSpeed = 20.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
