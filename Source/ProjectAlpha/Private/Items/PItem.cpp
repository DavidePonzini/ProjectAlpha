// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PItem.h"

#include "PInventoryComponent.h"



UPItem::UPItem()
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

bool UPItem::IsStackable() const
{
	return bIsStackable;
}

int UPItem::GetCategory() const
{
	return Category;
}

int UPItem::GetMaxCount() const
{
	return MaxCount;
}

