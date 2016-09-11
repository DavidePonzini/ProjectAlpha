// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Components/PStatsComponent.h"
#include "PInventoryComponent.h"
#include "PCharacter.generated.h"

UCLASS()
class PROJECTALPHA_API APCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APCharacter();

// Components
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		UPStatsComponent* Stats;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
		UPInventoryComponent* Inventory;
	
};
