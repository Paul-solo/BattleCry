// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CameraLogic.generated.h"

class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UBoxComponent;

UCLASS()
class BATTLECRY_API ACameraLogic : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraLogic();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);
	void MouseLook(const FInputActionValue& Value);
	void MouseWheel(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, Category = Camera)
	float MovementSpeed = 750.0f;

	UPROPERTY(EditAnywhere, Category = Camera)
	float CameraVerticalSpeed = 1000000.0f;

	UPROPERTY(EditAnywhere, Category = Camera)
	UCameraComponent* CameraMain;

	UPROPERTY(EditAnywhere, Category = Camera)
	AActor* CameraHero = nullptr;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionBox;

	// Input
	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* MainCameraInputContext;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MouseLookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* CameraVerticalMovementAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool isPanning = true;

	FVector2D MovementVector = FVector2D();
	FVector2D LookVector = FVector2D();
	float CameraElevation = 0.0f;
};
