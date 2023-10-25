// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "InputActionValue.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;
	
	void Move(const FInputActionValue& Value);
	
	virtual void BeginPlay() override;

	virtual void SetupInputComponent();

};
