// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Subtitle.h"
#include "Dialog.generated.h"


// UCLASS()
// class BASICDIALOG_API UDialog : public UObject
// {
// 	GENERATED_BODY()
// };



USTRUCT(BlueprintType)
struct FDialog : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	FString QuestionExcerpt;

	UPROPERTY(EditAnywhere)
	USoundBase* SFX;

	UPROPERTY(EditAnywhere)
	TArray<FSubtitle> Subtitles;


	UPROPERTY(EditAnywhere)
	bool bShouldAIAnswer;
};