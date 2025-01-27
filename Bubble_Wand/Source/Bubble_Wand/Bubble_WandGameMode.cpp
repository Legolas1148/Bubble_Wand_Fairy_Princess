// Copyright Epic Games, Inc. All Rights Reserved.

#include "Bubble_WandGameMode.h"
#include "Bubble_WandCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABubble_WandGameMode::ABubble_WandGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}


}
