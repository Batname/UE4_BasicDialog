// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Dialog.h"
#include "DialogUI.generated.h"

/**
 * 
 */
UCLASS()
class BASICDIALOG_API UDialogUI : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly)
	FString SubtitleToDisplay;


	UFUNCTION(BlueprintCallable, Category = DialogSystem)
	void UpdateSubtitles(TArray<FSubtitle> Subtitles);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FString> Questions;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = DialogSystem)
	void Show();
};
