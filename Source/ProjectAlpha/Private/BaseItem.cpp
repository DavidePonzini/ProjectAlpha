// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "BaseItem.h"

UBaseItem::UBaseItem()
{
}

UBaseItem::~UBaseItem()
{
	/*
	if (bIsEquipped)
	UnEquip();
	*/
}

void UBaseItem::Equip(APawn* WhoEquipped)
{
}

void UBaseItem::UnEquip()
{
}

void UBaseItem::Drop()
{
}
/*
bool UBaseItem::CanAfford(APawn* Buyer) const
{
return false;
}
*/