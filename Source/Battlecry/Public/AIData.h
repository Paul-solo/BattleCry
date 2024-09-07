#pragma once

UENUM(BlueprintType)
enum States
{
	LYING_DOWN,
	CROUCHING,
	STANDING,
	FRENZYING,
	SURRENDERING
};

UENUM(BlueprintType)
enum ActionStates
{
	WAITING,
	ATTACKING,
	ON_PATROL
};

UENUM(BlueprintType)
enum EFormation
{
	Line	UMETA(DisplayName = "Line Formation"),
	Column,
	Wedge,
	Testudo
};
