// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PItem.h"


UPItem::UPItem()
	: Super()
{
	bCanBeEquipped = false;
}

void UPItem::Equip(UPInventoryComponent* CharacterInventory, EPItemSlot Slot)
{
	// Nothing to do here, UItems cannot be equipped
}

void UPItem::UnEquip(UPInventoryComponent* CharacterInventory, EPItemSlot Slot)
{
	// Nothing to do here, UItems cannot be equipped
}

