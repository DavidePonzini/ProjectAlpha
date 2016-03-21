// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "BaseInventoryItem.h"

BaseInventoryItem::BaseInventoryItem()
{
}

BaseInventoryItem::~BaseInventoryItem()
{
	if (bIsEquipped)
		UnEquip();
}

void BaseInventoryItem::Equip(APawn* WhoEquipped)
{
}

void BaseInventoryItem::UnEquip()
{
}

void BaseInventoryItem::Drop()
{
}

bool BaseInventoryItem::CanAfford(APawn* Buyer) const
{
	return false;
}
