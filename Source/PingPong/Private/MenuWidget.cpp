// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

#include "Kismet/GameplayStatics.h"

void UMenuWidget::OnStartGame()
{
	UGameplayStatics::OpenLevel(GetWorld(),FName(TEXT("StandartMap")));
}

void UMenuWidget::OnStartGame2Players()
{
	
}


void UMenuWidget::OnStatistics()
{
	
}

void UMenuWidget::OnExitGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(),GetWorld()->GetFirstPlayerController(),EQuitPreference::Quit,false);
}


void UMenuWidget::NativeConstruct()
{
	if (StartGameButton != nullptr)
	{
		StartGameButton->OnClicked.AddDynamic(this,&UMenuWidget::OnStartGame);
	}
	if (StartGame2PlayersButton != nullptr)
	{
		StartGame2PlayersButton->OnClicked.AddDynamic(this,&UMenuWidget::OnStartGame2Players);
	}
	if (StatisticsButton != nullptr)
	{
		StatisticsButton->OnClicked.AddDynamic(this,&UMenuWidget::OnStatistics);
	}
	if (ExitGameButton != nullptr)
	{
		ExitGameButton->OnClicked.AddDynamic(this,&UMenuWidget::OnExitGame);
	}
}
