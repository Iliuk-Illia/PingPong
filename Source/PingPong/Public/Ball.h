// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"
#include "Sound/SoundCue.h"
#include "Ball.generated.h"

UCLASS()
class PINGPONG_API ABall : public APawn
{
	GENERATED_BODY()

public:
	ABall();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> GoalZoneClass;
	
	UPROPERTY(EditAnywhere)
	UMaterial* OnMaterial;
	
	UPROPERTY(EditDefaultsOnly)
	USoundCue* Noise;
	
	UPROPERTY(EditDefaultsOnly)
	USoundCue* Goal;
	
	UPROPERTY(EditAnywhere)
	FVector Velocity;

	UPROPERTY(EditAnywhere)
	float SpeedMultiplier;

	UPROPERTY(EditAnywhere)
	FTransform SpawnTransform;

	UPROPERTY()
	UFloatingPawnMovement* FloatingPawnMovement;

	UPROPERTY()
    USphereComponent* Sphere;

	UPROPERTY()
	UStaticMeshComponent* StaticMesh;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
						AActor* OtherActor,
						UPrimitiveComponent* OtherComp,
						int OtherBodyIndex,
						bool FromSweep,
						const FHitResult& SweepResult);
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
