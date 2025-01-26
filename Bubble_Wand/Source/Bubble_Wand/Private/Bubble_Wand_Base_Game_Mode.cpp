// Fill out your copyright notice in the Description page of Project Settings.


#include "Bubble_Wand_Base_Game_Mode.h"
#include "Player/Micelle.h"
#include "UObject/ConstructorHelpers.h"

ABubble_Wand_Base_Game_Mode::ABubble_Wand_Base_Game_Mode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Micelle_BP.Micelle_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
