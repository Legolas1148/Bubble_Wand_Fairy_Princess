// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Micelle.h"
#include "Camera/CameraComponent.h"
#include "Bubble.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
AMicelle::AMicelle()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

	ShootingCooldown = 1.0f;
	bCanShoot = true;

    // Camera Boom
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 400.0f; // Distance from the character model
    CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	//Follow Camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void AMicelle::BeginPlay()
{
	Super::BeginPlay();
	
	DefaultGravityScale = GetCharacterMovement()->GravityScale;
}

// Called every frame
void AMicelle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsGliding)
	{
		FVector ForwardMovement = GetActorForwardVector() * 100.0f;
		FVector RightMovement = GetActorRightVector() * 100.0f;
		AddMovementInput(ForwardMovement, 1.0f);
		AddMovementInput(RightMovement, 1.0f);
	}
}

// Called to bind functionality to input
void AMicelle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	jumpCount = 0;
	maxJumpCount = 2;

	bIsGliding = false;
	GlideGravityScale = 0.2f;
	DefaultGravityScale = 2.0f;

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMicelle::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMicelle::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &AMicelle::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AMicelle::Turn);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMicelle::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMicelle::StopJumping);

	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AMicelle::shoot);
}

void AMicelle::MoveForward(float input)
{
	AddMovementInput(GetActorForwardVector(), input);
}

void AMicelle::MoveRight(float input)
{
	AddMovementInput(GetActorRightVector(), input);
}

void AMicelle::LookUp(float input)
{
	AddControllerPitchInput(input);
}

void AMicelle::Turn(float input)
{
	AddControllerYawInput(input);
}

void AMicelle::Jump()
{
	if (jumpCount < maxJumpCount)
	{
		Super::Jump();
		jumpCount++;
	}
	else if (jumpCount == maxJumpCount && !(GetCharacterMovement()->IsMovingOnGround()))
	{
		StartGlide();
	}
}

void AMicelle::StopJumping()
{
	Super::StopJumping();
}

void AMicelle::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	StopGlide();
	jumpCount = 0;
}

void AMicelle::StartGlide()
{
	bIsGliding = true;
	GetCharacterMovement()->GravityScale = GlideGravityScale;

	GetCharacterMovement()->MaxFlySpeed = 600.0f;
}


void AMicelle::StopGlide()
{
	if (bIsGliding)
	{
		bIsGliding = false;
		GetCharacterMovement()->GravityScale = DefaultGravityScale;
		GetCharacterMovement()->MaxFlySpeed = 0.0f;
	}
}

void AMicelle::shoot()
{
	if (bCanShoot && Bubble)
	{
		FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() + BubbleSpawnOffset;
		FRotator SpawnRotation = GetControlRotation();

		UWorld* World = GetWorld();
		if (World)
		{
			GetWorld()->SpawnActor<ABubble>(Bubble, SpawnLocation, SpawnRotation);
		}

		bCanShoot = false;
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(
			TimerHandle, 
			this, 
			&AMicelle::ResetCooldown,
			ShootingCooldown,
			false);
	}
}

void AMicelle::ResetCooldown()
{
	bCanShoot = true;
}