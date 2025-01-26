// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Micelle.generated.h"

UCLASS()
class BUBBLE_WAND_API AMicelle : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMicelle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//Glide-related variables
	bool bIsGliding;
	float GlideGravityScale;
	float DefaultGravityScale;

	//Glide Input function
	void StartGlide();
	void StopGlide();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Movement functions
	void MoveForward(float input);
	void MoveRight(float input);
	virtual void Jump() override;
	virtual void StopJumping() override;

	//Look Funcitons
	void LookUp(float input);
	void Turn(float input);

	//Camera functions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* FollowCamera;

	//Shooting functions
	bool bCanShoot;
	void ResetCooldown();
	void shoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	float ShootingCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	TSubclassOf<class ABubble> Bubble;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	FVector BubbleSpawnOffset = FVector(0.0f, 100.0f, 0.0f);

	//Stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float speedMultiplier = 1.0f;

	int jumpCount;
	int maxJumpCount;

	virtual void Landed(const FHitResult& Hit) override;
};