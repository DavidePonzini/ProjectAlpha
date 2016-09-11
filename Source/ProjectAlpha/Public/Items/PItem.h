// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectAlpha.h"
#include "PItemSlot.h"
#include "PInventoryComponent.h"
#include "PItem.generated.h"


UCLASS(Blueprintable, BlueprintType)
class PROJECTALPHA_API UPItem : public UObject
{
	GENERATED_BODY()


public:
	UPItem();

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
		TSubclassOf<AActor> EquipItem;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
		TSubclassOf<AActor> PickupItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data")
		int Price;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data")
		FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data")
		bool bCanBeEquipped;

public:
	virtual void Equip(UPInventoryComponent* CharacterInventory, EPItemSlot Slot);
	virtual void UnEquip(UPInventoryComponent* CharacterInventory, EPItemSlot Slot);
};
