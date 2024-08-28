// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BattleCryHUD.generated.h"

/**
 * 
 */

class UDragBox;

UCLASS()
class BATTLECRY_API ABattleCryHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UDragBox* DragBox;

private:
	UPROPERTY(EditDefaultsOnly, Category = BattleCry)
	TSubclassOf<UDragBox> BattleCryOverlay;

protected:
	virtual void BeginPlay() override;
};
