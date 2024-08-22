// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "RTSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BATTLECRY_API ARTSGameMode : public AGameMode
{
	GENERATED_BODY()
public: 
	int EnnemyLeft = 0;
};
