// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


UCLASS(abstract)
class PROJECTALPHA_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	float fHealthMax;
	float fHealth;

	float fKiMax;
	float fKi;

	float fStaminaMax;
	float fStamina;

	//TMap<AActor, int> Inventory;

public:
	ABaseCharacter();

/*	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void EquipItem(AActor* item);
*/
	UFUNCTION(BlueprintCallable, Category = "Stats|Health")
		float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Stats|Health")
		float GetHealthMax() const;

	UFUNCTION(BlueprintCallable, Category = "Stats|Health")
		float GetHealthPercent() const;

	UFUNCTION(BlueprintCallable, Category = "Stats|Ki")
		float GetKi() const;

	UFUNCTION(BlueprintCallable, Category = "Stats|Ki")
		float GetKiMax() const;

	UFUNCTION(BlueprintCallable, Category = "Stats|Ki")
		float GetKiPercent() const;

	UFUNCTION(BlueprintCallable, Category = "Stats|Stamina")
		float GetStamina() const;

	UFUNCTION(BlueprintCallable, Category = "Stats|Stamina")
		float GetStaminaMax() const;

	UFUNCTION(BlueprintCallable, Category = "Stats|Stamina")
		float GetStaminaPercent() const;
/*
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		FString TEST_GetInventoryText() const;
*/
};
