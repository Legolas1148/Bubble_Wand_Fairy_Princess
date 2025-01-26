// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bubble.generated.h"

UCLASS()
class BUBBLE_WAND_API ABubble : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABubble();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Movement")
	class UProjectileMovementComponent* ProjectileMovement;
	
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Collision")
	class USphereComponent* CollisionComponent;
	
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Visual")
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Combat")
	float Damage = 10.0f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
