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


class UMGAsyncTask : public FNonAbandonableTask
{
	TArray<FSubtitle> Subs;

	UDialogUI* DialogUI;

public:

	UMGAsyncTask(TArray<FSubtitle>& Subs, UDialogUI* DialogUI)
	{
		this->Subs = Subs;
		this->DialogUI = DialogUI;
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(UMGAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}

	void DoWork()
	{
		for (int32 i = 0; i < Subs.Num(); i++)
		{
			//Sleep means that we pause this thread for the given time
			FPlatformProcess::Sleep(Subs[i].AssociatedTime);

			//Update our subtitles after the thread comes back
			DialogUI->SubtitleToDisplay = Subs[i].Subtitle;
		}

		FPlatformProcess::Sleep(1.f);

		DialogUI->SubtitleToDisplay = FString("");
	}
};