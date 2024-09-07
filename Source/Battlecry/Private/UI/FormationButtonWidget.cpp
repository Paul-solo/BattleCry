// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TextBlock.h"
#include "UI/FormationButtonWidget.h"

void UFormationButtonWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	ButtonIndex = static_cast<int>(Formation);

	if (ButtonText)
	{
		ButtonText->SetText(UEnum::GetDisplayValueAsText(Formation));
	}
}
