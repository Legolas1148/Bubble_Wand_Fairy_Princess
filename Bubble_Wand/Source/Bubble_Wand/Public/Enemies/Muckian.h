// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Muckian.generated.h"

UCLASS()
class BUBBLE_WAND_API AMuckian : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMuckian();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Muckian")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Muckian")
	float Speed;
};
