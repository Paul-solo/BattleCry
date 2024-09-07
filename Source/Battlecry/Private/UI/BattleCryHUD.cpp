// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BattleCryHUD.h"
#include "DragBox.h"

void ABattleCryHUD::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();

	if (World)
	{
		APlayerController* Controller = World->GetFirstPlayerController();

		if (Controller && BattleCryOverlay)
		{
			DragBox = CreateWidget<UDragBox>(Controller, BattleCryOverlay);
			DragBox->AddToViewport();
		}
	}
}
