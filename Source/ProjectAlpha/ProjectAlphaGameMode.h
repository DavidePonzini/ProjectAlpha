// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "GameFramework/GameMode.h"
#include "ProjectAlphaGameMode.generated.h"


class APCharacter;


UCLASS()
class PROJECTALPHA_API AProjectAlphaGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
public:
	AProjectAlphaGameMode();

	/** Called when the game starts. */
	virtual void BeginPlay() override;


// Pawn
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default Classes|Pawn")
		TSubclassOf<APCharacter> DefaultPawn;

	UFUNCTION(BlueprintCallable, Category = "Default Classes|HUD")
		void SetDefaultPawn(TSubclassOf<APCharacter> PawnClass);

// HUD
public:
	/** Remove the current menu widget and create a new one from the specified class, if provided. */
	UFUNCTION(BlueprintCallable, Category = "Default Classes|HUD")
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	/** The widget class we will use as our menu when the game starts. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default Classes|HUD")
		TSubclassOf<UUserWidget> StartingWidgetClass;

	/** The widget instance that we are using as our menu. */
	UPROPERTY()
		UUserWidget* CurrentWidget;
};