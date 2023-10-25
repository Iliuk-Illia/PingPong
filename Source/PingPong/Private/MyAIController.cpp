// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	
		 /*(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this.GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}*/
	
}

void AMyAIController::Move(const FInputActionValue& Value)
{
	float MovementValue = Value.Get<float>();
	
	// find out which way is forward
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	
	// get right vector 
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn)
	{
		ControlledPawn->AddMovementInput(Direction, MovementValue);
	}
	
}

void AMyAIController::SetupInputComponent()
{

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyAIController::Move);
	}

}