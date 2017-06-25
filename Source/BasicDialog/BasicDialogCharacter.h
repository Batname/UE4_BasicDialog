// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "AICharacter.h"
#include "DialogUI.h"

#include "BasicDialogCharacter.generated.h"

UCLASS(config=Game)
class ABasicDialogCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	ABasicDialogCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

/* ----- Dialog system logic ----- */
private:
	bool bIsTalking;

	bool bIsInTalkRange;

	void ToogleTalking();

	/** The pawn that the player is currently talking to */
	AAICharacter* AssociatedPawn;

	/** Reffer to lines */
	UDataTable* AvailableLines;

	FDialog* RetriveDialog(UDataTable* TableToSearch, FName RowName);

public:
	void GeneratePlayerLines(UDataTable& PlayerLines);

	UPROPERTY(BlueprintReadOnly)
	TArray<FString> Questions;

	UFUNCTION(BlueprintCallable, Category = DialogSystem)
	void Talk(FString Excerpt, TArray<FSubtitle>& Subtitles);

	void SetTalkRangeStatus(bool Status) { bIsInTalkRange = Status; }

	void SetAssociatedPawn(AAICharacter* Pawn) { AssociatedPawn = Pawn; }

	UDialogUI* GetUI() { return UI; }

protected:
	UPROPERTY(VisibleAnywhere)
	UAudioComponent* AudioComp;

	UFUNCTION(BlueprintImplementableEvent, Category = DialogSystem)
	void ToggleUI();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UDialogUI* UI;

/* ----- Dialog system logic ----- */
};

