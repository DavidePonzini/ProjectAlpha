// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "BaseInventoryItem.h"

UBaseInventoryItem::UBaseInventoryItem()
{
}

UBaseInventoryItem::~UBaseInventoryItem()
{
/*
	if (bIsEquipped)
		UnEquip();
*/
}

void UBaseInventoryItem::Equip(APawn* WhoEquipped)
{
}

void UBaseInventoryItem::UnEquip()
{
}

void UBaseInventoryItem::Drop()
{
}
/*
bool UBaseInventoryItem::CanAfford(APawn* Buyer) const
{
	return false;
}
*/