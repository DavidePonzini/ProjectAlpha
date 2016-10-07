// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectAlpha.h"
#include "PItemSlot.h"
#include "PInventoryItem.h"
#include "PItemCategory.h"
#include "PItem.generated.h"


class UPInventoryComponent;


UCLASS(Blueprintable, BlueprintType)
class PROJECTALPHA_API UPItem : public UObject, public PInventoryItem
{
	GENERATED_BODY()

public:
	UPItem();

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
		TSubclassOf<AActor> EquipItem;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
		TSubclassOf<AActor> PickupItem;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Base Info")
		int Price;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Base Info")
		FString Name;
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Category")
		TEnumAsByte<EPItemCategory> Category;

	virtual int GetCategory() const override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stacking")
		bool bIsStackable;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stacking")
		int MaxCount;

	virtual bool IsStackable() const override;
	virtual int GetMaxCount() const override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipping")
		bool bCanBeEquipped;
	
	virtual void Equip(UPInventoryComponent* CharacterInventory, EPItemSlot Slot);
	virtual void UnEquip(UPInventoryComponent* CharacterInventory, EPItemSlot Slot);
};
