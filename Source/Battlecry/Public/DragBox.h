// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DragBox.generated.h"

/**
 * 
 */
UCLASS()
class BATTLECRY_API UDragBox : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetDragBoxPosition(float x, float y);
	void SetDragBoxSize(float width, float height);

	UPROPERTY(meta = (BindWidget))
	class UBorder* DragBox;
};
