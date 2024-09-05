// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit.h"
#include "AIController.h"

// Sets default values
AUnit::AUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SelectedPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Selected Plane"));
	SelectedPlane->SetupAttachment(GetRootComponent());
}

void AUnit::MoveToLocation(FVector Location)
{
	// Check if there are waypoints to travel between and if the waypoint still exists (It might have been destroyed)
	AAIController* AIController = Cast<AAIController>(GetController());

	/*if (AIController == nullptr || Waypoints.Num() == 0 || Waypoints[CurrentWaypointIndex] == nullptr)
	{
		return;
	}*/

	// Choose next waypoint
	FVector CurrentLocation = GetActorLocation();  // get the currect actor location 
	FVector TargetLocation  = Location;

	// When we get close to the targe, then change to the next way point 
	float MinimumWaypointDistance = 200.0f;

	if (FVector::Dist(TargetLocation, CurrentLocation) < MinimumWaypointDistance)
	{
		ActionState = ActionStates::ON_PATROL;
		/*CurrentWaypointIndex++;

		if (CurrentWaypointIndex >= Waypoints.Num())
		{
			CurrentWaypointIndex = 0;
		}*/
	}
	else
	{
		AIController->MoveToLocation(TargetLocation);
		ActionState = ActionStates::WAITING;
	}
}

// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SelectedPlane->SetWorldRotation(SelectedPlane->GetComponentRotation() + (FRotator(0.0f, SelectedPlaneSpeed, 0.0f) * DeltaTime));

	if (isSelected)
	{
		SelectedPlane->SetVisibility(true);
	}
	else
	{
		SelectedPlane->SetVisibility(false);
	}
}

// Called to bind functionality to input
void AUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

