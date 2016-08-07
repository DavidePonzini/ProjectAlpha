// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "BaseCharacter.h"


ABaseCharacter::ABaseCharacter()
	: Super()
{
	fHealthMax = 1000.0f;
	fHealth = 850.0f;

	fKiMax = 200.0f;
	fKi = 50.0f;

	fStaminaMax = 1000.0f;
	fStamina = 623.0f;
}

float ABaseCharacter::GetHealth() const
{
	return fHealth;
}

float ABaseCharacter::GetHealthMax() const
{
	return fHealthMax;
}

float ABaseCharacter::GetKi() const
{
	return fKi;
}

float ABaseCharacter::GetKiMax() const
{
	return fKiMax;
}

float ABaseCharacter::GetStamina() const
{
	return fStamina;
}

float ABaseCharacter::GetStaminaMax() const
{
	return fStaminaMax;
}

float ABaseCharacter::GetHealthPercent() const
{
	return GetHealth() / GetHealthMax();
}

float ABaseCharacter::GetKiPercent() const
{
	return GetKi() / GetKiMax();
}

float ABaseCharacter::GetStaminaPercent() const
{
	return GetStamina() / GetStaminaMax();
}

/*
void ABaseCharacter::EquipItem(AActor * item)
{
	const FName socketName = "BackWeaponHolsterMelee1";

	item->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, socketName);
}

FString ABaseCharacter::TEST_GetInventoryText() const
{
	TArray<AActor> keys;

	Inventory.GenerateKeyArray(keys);

	return "TO DO";
}
*/