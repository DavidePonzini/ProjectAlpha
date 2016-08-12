// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CharacterStats.h"
#include "BaseCharacter.generated.h"


UCLASS(abstract)
class PROJECTALPHA_API ABaseCharacter : public ACharacter, public ICharacterStats
{
	GENERATED_BODY()

public:
	ABaseCharacter();

public:
	UPROPERTY(EditAnywhere, Category = "Stats")
		FStatData Health = Stats[EStatValue::Health];
};
