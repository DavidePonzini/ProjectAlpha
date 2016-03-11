// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "BaseItem.h"


// Sets default values
ABaseItem::ABaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Price
	PriceGold = 0;
	PriceSilver = 0;
	PriceBronze = 0;

	// Inventory slot
	Slot = EInventorySlot::NONE;
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

EInventorySlot ABaseItem::GetInventorySlot()
{
	return Slot;
}

bool ABaseItem::CanAfford(APawn * Buyer) const
{
	return false;
}

void ABaseItem::SetPriceGold(int32 Value)
{
	if (Value < 0)
		Value = 0;

	PriceGold = Value;
}

void ABaseItem::SetPriceSilver(int32 Value)
{
	if (Value < 0)
		Value = 0;

	PriceSilver = Value;
}

void ABaseItem::SetPriceBronze(int32 Value)
{
	if (Value < 0)
		Value = 0;

	PriceBronze = Value;
}

int32 ABaseItem::GetPriceGold() const
{
	return PriceGold;
}

int32 ABaseItem::GetPriceSilver() const
{
	return PriceSilver;
}

int32 ABaseItem::GetPriceBronze() const
{
	return PriceBronze;
}

