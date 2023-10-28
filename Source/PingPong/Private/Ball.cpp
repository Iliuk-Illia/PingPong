// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

#include "PlayerCharacter.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABall::ABall()
{
 	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->BoundsScale=0.5;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(RootComponent);
}

void ABall::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this,&ABall::OnOverlapBegin);
	
	if (UKismetMathLibrary::RandomBool())
	{
		Velocity.X = 0;
		Velocity.Y = 1;
		Velocity.Z = 0;

	}
	else
	{
		Velocity.X = 0;
		Velocity.Y = -1;
		Velocity.Z = 0;
	}

	
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FloatingPawnMovement->AddInputVector(Velocity);

}

void ABall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ABall::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	if (Cast<AStaticMeshActor>(OtherActor))
	{
		if (Noise != nullptr)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), Noise);
		}
		Velocity.X = Velocity.X * -1.0;
	}
	else
	{
		if (APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor))
		{
			if (Cast<UBoxComponent>(OtherComp))
			{
				if (Noise != nullptr)
				{
					UGameplayStatics::PlaySound2D(GetWorld(), Noise);
				}

				if (PlayerCharacter->Energy)
				{
					Velocity.X = Velocity.X + PlayerCharacter->VelocityToEnergy;
					Velocity.Y = Velocity.Y * -1.0;
				}
				else
				{
					
					Velocity.X = Velocity.X + (PlayerCharacter->GetVelocity().X/PlayerCharacter->GetMovementComponent()->GetMaxSpeed());
					Velocity.Y = Velocity.Y * -1.0;
				}
				
				FloatingPawnMovement->MaxSpeed = FloatingPawnMovement->GetMaxSpeed()*SpeedMultiplier;

				PlayerCharacter->Energy = false;
				if (OnMaterial != nullptr)
				{
					PlayerCharacter->StaticMesh->SetMaterial(0,OnMaterial);
				}
			}
		}
		else
		{
			if (true)//GoalZoneClass Cast<GoalZoneClass>(OtherActor))
			{

				if (Noise != nullptr)
				{
					UGameplayStatics::PlaySound2D(GetWorld(), Goal);
				}
			}
			
		}
	}
	
}

