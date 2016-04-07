// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "Item.h"
#include "BaseCharacter.h"
#include "PickupActor.h"

UItem::UItem()
{
}

UItem::~UItem()
{
	/*
	if (bIsEquipped)
	UnEquip();
	*/
}

void UItem::Equip(ABaseCharacter* WhoEquipped)
{
}

void UItem::UnEquip()
{
}

void UItem::Drop()
{
}
/*
bool UItem::CanAfford(ABaseCharacter* Buyer) const
{
	return false;
}
*/