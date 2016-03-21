// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "BaseItem.h"


// Sets default values
ABaseItem::ABaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Price
	for (uint8 i = 0; i < (uint8)ECurrencyType::_NO_ELEMS; i++)
		Price.Add(0);

	// Inventory slot
	Slot = EEquipSlot::NONE;
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

EEquipSlot ABaseItem::GetEquipSlot()
{
	return Slot;
}

bool ABaseItem::CanAfford(APawn * Buyer) const
{
	return false;
}
/*
void ABaseItem::SetPrice(int64 Value, ECurrencyType CurrencyType)
{
	Price[(uint8)CurrencyType] = Value;
}

int64 ABaseItem::GetPrice(ECurrencyType CurrencyType) const
{
	return Price[(uint8)CurrencyType];
}
*/