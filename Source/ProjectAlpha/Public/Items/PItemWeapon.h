// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PItemEquippable.h"
#include "PWeaponType.h"
#include "PItemWeapon.generated.h"


UCLASS()
class PROJECTALPHA_API UPItemWeapon : public UPItemEquippable
{
	GENERATED_BODY()

public:
	UPItemWeapon();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data|Weapon")
		TEnumAsByte<EPWeaponType> WeaponType;

public:
	virtual void Equip(UPInventoryComponent* CharacterInventory, EPItemSlot Slot) override;
	virtual void UnEquip(UPInventoryComponent* CharacterInventory, EPItemSlot Slot) override;
};
