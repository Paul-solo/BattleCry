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
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(FName("Collision Mesh"));
	CameraMain = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraMain->SetupAttachment(CollisionBox);
}

// Called when the game starts or when spawned
void ACameraLogic::BeginPlay()
{
	Super::BeginPlay();
	
	// Enhanced Input Input Mapping Controller (IMC) Setup for The Castle Main Game Character Harker
	APlayerController* PlayerController = Cast<APlayerController>(GetController());

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

	if (isPanning)
	{
		const FVector ForwardDirection = GetActorForwardVector() * MovementVector.Y;
		const FVector RightDirection   = GetActorRightVector()   * MovementVector.X;
		
		FVector MoveDirection = FVector(ForwardDirection.X + RightDirection.X, ForwardDirection.Y + RightDirection.Y, CameraElevation * CameraVerticalSpeed);
		MoveDirection /= MoveDirection.Size();

		const FVector2D LookDelta = LookVector * DeltaTime * MovementSpeed;

		FRotator Rotation = GetActorRotation() + FRotator(LookDelta.Y, LookDelta.X, 0.0f);

		if (Rotation.Pitch > 70.0f)
		{
			Rotation.Pitch = 70.0f;
		}
		else if (Rotation.Pitch < -45.0f)
		{
			Rotation.Pitch = -45.0f;
		}

		SetActorLocation(GetActorLocation() + (MoveDirection * DeltaTime * MovementSpeed));
		SetActorRotation(Rotation);
	}
	else
	{
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
