// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraLogic.h"
#include <Camera/CameraComponent.h>
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <Components/BoxComponent.h>
#include <Components/WidgetComponent.h>
#include <Kismet/GameplayStatics.h>
#include <BattleCryHUD.h>
#include <DragBox.h>
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Unit.h"

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

	//GotoBanner = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Banner"));
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

	HUD = Cast<ABattleCryHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
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

	float CameraMultiplier = 1.0f;

	if (isCameraSpedUp)
	{
		CameraMultiplier = 4.0f;
	}
	
	SetActorLocation(GetActorLocation() + (MoveDirection * DeltaTime * MovementSpeed * CameraMultiplier));
	
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

		if (isDragging)
		{
			HUD->DragBox->SetVisibility(ESlateVisibility::Visible);

			float mouseX;
			float mouseY;

			UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(mouseX, mouseY);

			const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
			float ResolutionRatio = (ViewportSize.X / ViewportSize.Y);

			float width  = abs(mouseX - MouseDragInitialX);
			float height = abs(mouseY - MouseDragInitialY);

			float newposX = MouseDragInitialX;
			float newposY = MouseDragInitialY;

			if (MouseDragInitialX > mouseX)
			{
				newposX = mouseX;
			}

			if (MouseDragInitialY > mouseY)
			{
				newposY = mouseY;
			}

			HUD->DragBox->SetDragBoxPosition(newposX, newposY);
			HUD->DragBox->SetDragBoxSize(width, height);
		}
		else
		{
			HUD->DragBox->SetVisibility(ESlateVisibility::Hidden);
		}
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
		EnhancedInputComponent->BindAction(StartDragBoxAction, ETriggerEvent::Triggered, this, &ACameraLogic::StartDragBox);
		EnhancedInputComponent->BindAction(StartDragBoxAction, ETriggerEvent::Completed, this, &ACameraLogic::StartDragBox);
		EnhancedInputComponent->BindAction(SpeedUpCameraAction, ETriggerEvent::Triggered, this, &ACameraLogic::SpeedUpCamera);
		EnhancedInputComponent->BindAction(SpeedUpCameraAction, ETriggerEvent::Completed, this, &ACameraLogic::SpeedUpCamera);
		EnhancedInputComponent->BindAction(MoveUnitAction, ETriggerEvent::Triggered, this, &ACameraLogic::SendMoveUnitCommand);
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

void ACameraLogic::StartDragBox(const FInputActionValue& Value)
{
	if (isDragging == false)
	{
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(MouseDragInitialX, MouseDragInitialY);

		HUD->DragBox->SetDragBoxPosition(MouseDragInitialX, MouseDragInitialY);
	}

	isDragging = Value.Get<bool>();
}

void ACameraLogic::SpeedUpCamera(const FInputActionValue& Value)
{
	isCameraSpedUp = Value.Get<bool>();
}

void ACameraLogic::SendMoveUnitCommand(const FInputActionValue& Value)
{
	TArray<AActor*> FoundActors;
	TSubclassOf<AUnit> ClassToFind = AUnit::StaticClass();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);

	FHitResult HitResult;

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	//GotoBanner->SetRelativeLocation(Location);

	float x = 0.0f;

	for (int i = 0; i < FoundActors.Num(); i++)
	{
		/*if (i % 5 == 0)
		{
			x += 25.0f;
		}*/

		Cast<AUnit>(FoundActors[i])->MoveToLocation(HitResult.Location + (FVector(x, 30.0f, 0.0f) * i));
	}
}
