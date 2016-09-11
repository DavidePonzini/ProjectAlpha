// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "ProjectAlphaGameMode.h"

#include "PPlayerCharacter.h"


AProjectAlphaGameMode::AProjectAlphaGameMode()
{
	DefaultPawnClass = APPlayerCharacter::StaticClass();
}

void AProjectAlphaGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetDefaultPawn(DefaultPawn);

	ChangeMenuWidget(StartingWidgetClass);
}

void AProjectAlphaGameMode::SetDefaultPawn(TSubclassOf<APCharacter> PawnClass)
{
//	DefaultPawnClass = DefaultPawnClass;
}

void AProjectAlphaGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = NULL;
	}

	if (NewWidgetClass)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}