// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* StartGameButton;

	UFUNCTION()
	void OnStartGame();
	
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* StartGame2PlayersButton;

	UFUNCTION()
	void OnStartGame2Players();
	
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* StatisticsButton;

	UFUNCTION()
	void OnStatistics();
	
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* ExitGameButton;
	
	UFUNCTION()
	void OnExitGame();
	
	void virtual NativeConstruct() override;
};
