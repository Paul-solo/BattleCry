// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIData.h"
#include "Engine/DataAsset.h"
#include "FormationDataAsset.generated.h"

UCLASS()
class BATTLECRY_API UFormationDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Settings")
	FPrimaryAssetType DataType;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId(DataType, GetFName());
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	TEnumAsByte<EFormation> FormationType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	FText Offset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	bool Alternate;

};
