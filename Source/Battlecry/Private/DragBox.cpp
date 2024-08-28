// Fill out your copyright notice in the Description page of Project Settings.


#include "DragBox.h"
#include "Components/Border.h"

void UDragBox::SetDragBoxPosition(float x, float y)
{
	SetPositionInViewport(FVector2D(x, y));
}

void UDragBox::SetDragBoxSize(float width, float height)
{
	if (DragBox)
	{
		DragBox->SetDesiredSizeScale(FVector2D(width, height));
	}
}
