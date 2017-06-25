// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"
#include "Engine/DataTable.h"
#include "Subtitle.h"

#include "AICharacter.generated.h"

UCLASS()
class BASICDIALOG_API AAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAICharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnBoxOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	UFUNCTION()
	void OnBoxEndOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void Talk(USoundBase* SFX, TArray<FSubtitle> Subs);

public:
	void AnswerToCharacter(FName PlayerLine, TArray<FSubtitle>& SubtitleToDisplay, float delay);

	UDataTable* GetPlayerLines() { return PlayerLines; }

protected:

	UPROPERTY(VisibleAnywhere)	
	class UBoxComponent* BoxComp;

	UPROPERTY(VisibleAnywhere)
	class UAudioComponent* AudioComp;

	UPROPERTY(EditAnywhere, Category = DialogSystem)
	UDataTable* PlayerLines;


	UPROPERTY(EditAnywhere, Category = DialogSystem)
	UDataTable* AILines;
};
