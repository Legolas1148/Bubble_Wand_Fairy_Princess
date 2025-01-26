// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Muckian.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"

// Sets default values
AMuckian::AMuckian()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Damage = 20.0f;
	Speed = 200.0f;

	GetCharacterMovement()->MaxWalkSpeed = Speed;
}

// Called when the game starts or when spawned
void AMuckian::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuckian::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMuckian::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}