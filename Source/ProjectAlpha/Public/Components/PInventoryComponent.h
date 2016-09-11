// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"

#include "PItemSlot.h"
#include "PSpellSlot.h"

#include "PInventoryComponent.generated.h"


class APCharacter;

enum class EPWeaponType;

class UPItem;
class UPItemEquippable;
class UPItemWeapon;


struct FPItemStruct
{
	UPItem* Item;
	AActor* Actor;
};


UCLASS(ClassGroup = (Inventory), meta = (BlueprintSpawnableComponent))
class PROJECTALPHA_API UPInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPInventoryComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// Called when the game starts
	virtual void BeginPlay() override;

private:
	APCharacter* OwnerCharacter;

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void AddItem(TSubclassOf<UPItem> Item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void RemoveItem(TSubclassOf<UPItem> Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void EquipItem(TSubclassOf<UPItem> Item, EPItemSlot Slot);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void UnEquipItem(EPItemSlot Slot);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		TArray<TSubclassOf<UPItem>> GetItems() const;
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		int GetItemCount(TSubclassOf<UPItem> Item) const;

public:
	void EquipWeapon(UPItemWeapon* Weapon, EPItemSlot Slot);
	void UnEquipWeapon(EPItemSlot Slot);

	FName GetWeaponSocket(EPWeaponType ItemType) const;

	AActor* SpawnAndAttach(UClass* ActorToSpawn, USceneComponent* AttachComponent, FName AttachSocket);

public:
	TMap<TSubclassOf<UPItem>, int> Items;

	/** Map containing items slots and items equipped in them
	*	Only one item per slot is allowed */
	TMap<EPItemSlot, FPItemStruct> EquippedItems;

	/** Map containing spell slots and spells equipped in them
	*	Only one spell per slot is allowed */
	//TMap<ESpellSlot, UItemSpell*> EquippedSpells;


};

