// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PItemWeapon.h"

#include "PInventoryComponent.h"


UPItemWeapon::UPItemWeapon()
	: Super()
{
}

void UPItemWeapon::Equip(UPInventoryComponent* CharacterInventory, EPItemSlot Slot)
{
	CharacterInventory->EquipWeapon(this, Slot);
}

void UPItemWeapon::UnEquip(UPInventoryComponent* CharacterInventory, EPItemSlot Slot)
{
	CharacterInventory->UnEquipWeapon(Slot);
}
