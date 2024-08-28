// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraLogic.h"
#include <Camera/CameraComponent.h>
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <Components/BoxComponent.h>

// Sets default values
ACameraLogic::ACameraLogic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// For collisions to work, the root component must be the collision box
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(FName("Collision Mesh"));
	RootComponent = CollisionBox;

	CameraMain = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraMain->SetupAttachment(CollisionBox);
}

// Called when the game starts or when spawned
void ACameraLogic::BeginPlay()
{
	Super::BeginPlay();
	
	// Enhanced Input Input Mapping Controller (IMC) Setup for The Castle Main Game Character Harker
	PlayerController = Cast<APlayerController>(GetController());

	if (PlayerController)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MainCameraInputContext, 0);
		}
	}
}

// Called every frame
void ACameraLogic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector ForwardDirection = GetActorForwardVector() * MovementVector.Y;
	const FVector RightDirection = GetActorRightVector() * MovementVector.X;

	FVector MoveDirection = FVector(ForwardDirection.X + RightDirection.X, ForwardDirection.Y + RightDirection.Y, 0.0f);
	
	// Normalize vector (but avoid dividing by zero vector)
	if (MoveDirection.IsNearlyZero() == false)
	{
		MoveDirection /= MoveDirection.Size();
	}

	const float MinimumHeight = 100.0f;

	MoveDirection.Z = CameraElevation * CameraVerticalSpeed;

	if (MoveDirection.Z < 0.0f && GetActorLocation().Z + MoveDirection.Z < MinimumHeight)
	{
		MoveDirection.Z = 0.0f;
	}
	
	SetActorLocation(GetActorLocation() + (MoveDirection * DeltaTime * MovementSpeed));
	
	if (isPanning)
	{
		const FVector2D LookDelta = LookVector * DeltaTime * MovementSpeed;

		PlayerController->bShowMouseCursor = false;
		PlayerController->bEnableClickEvents = false;
		PlayerController->bEnableMouseOverEvents = false;

		FRotator Rotation = GetActorRotation() + FRotator(LookDelta.Y, LookDelta.X, 0.0f);

		if (Rotation.Pitch > 70.0f)
		{
			Rotation.Pitch = 70.0f;
		}
		else if (Rotation.Pitch < -45.0f)
		{
			Rotation.Pitch = -45.0f;
		}

		SetActorRotation(Rotation);
	}
	else
	{
		PlayerController->bShowMouseCursor = true;
		PlayerController->bEnableClickEvents = true;
		PlayerController->bEnableMouseOverEvents = true;
	}
}

// Called to bind functionality to input
void ACameraLogic::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Setup action bindings (input mapping)
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACameraLogic::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ACameraLogic::Move);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ACameraLogic::MouseLook);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Completed, this, &ACameraLogic::MouseLook);
		EnhancedInputComponent->BindAction(CameraVerticalMovementAction, ETriggerEvent::Triggered, this, &ACameraLogic::MouseWheel);
		EnhancedInputComponent->BindAction(CameraVerticalMovementAction, ETriggerEvent::Completed, this, &ACameraLogic::MouseWheel);
		EnhancedInputComponent->BindAction(ActivateMouseLookAction, ETriggerEvent::Triggered, this, &ACameraLogic::ActivateMouseLook);
		EnhancedInputComponent->BindAction(ActivateMouseLookAction, ETriggerEvent::Completed, this, &ACameraLogic::ActivateMouseLook);
	}
}

void ACameraLogic::Move(const FInputActionValue& Value)
{
	MovementVector = Value.Get<FVector2D>();
}

void ACameraLogic::MouseLook(const FInputActionValue& Value)
{
	LookVector = Value.Get<FVector2D>();
}

void ACameraLogic::MouseWheel(const FInputActionValue& Value)
{
	CameraElevation = Value.Get<float>();
}

void ACameraLogic::ActivateMouseLook(const FInputActionValue& Value)
{
	isPanning = Value.Get<bool>();
}
