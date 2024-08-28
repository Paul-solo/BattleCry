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
class UDragBox;
class ABattleCryHUD;

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
	void ActivateMouseLook(const FInputActionValue& Value);
	void StartDragBox(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, Category = Camera)
	float MovementSpeed = 750.0f;

	UPROPERTY(EditAnywhere, Category = Camera)
	float CameraVerticalSpeed = 1.0f;

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

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* ActivateMouseLookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* StartDragBoxAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	APlayerController* PlayerController;
	bool isPanning = false;
	bool isDragging = false;

	FVector2D MovementVector = FVector2D();
	FVector2D LookVector = FVector2D();
	float CameraElevation = 0.0f;

	ABattleCryHUD* HUD;
	UDragBox* DragBox;

	float MouseDragInitialX;
	float MouseDragInitialY;
};
