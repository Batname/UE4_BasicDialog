// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BasicDialogGameMode.h"
#include "BasicDialogCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABasicDialogGameMode::ABasicDialogGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
