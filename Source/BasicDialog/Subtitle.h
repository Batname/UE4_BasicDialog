// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Subtitle.generated.h"

/**
 * 
 */
// UCLASS()
// class BASICDIALOG_API USubtitle : public UObject
// {
// 	GENERATED_BODY()
	
	
	
	
// };

USTRUCT(BlueprintType)
struct FSubtitle : public FTableRowBase
{
	GENERATED_USTRUCT_BODY();


	/** the subtitle that will displayed for a specific period of the tile in UI */
	UPROPERTY(EditAnywhere)
	FString Subtitle;

	/** The relative time in seconds, that subtitle will appear */
	UPROPERTY(EditAnywhere)
	float AssociatedTime;
};
