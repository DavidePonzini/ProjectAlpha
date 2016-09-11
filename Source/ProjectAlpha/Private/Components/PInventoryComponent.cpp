// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "Components/PInventoryComponent.h"

#include "Character/PCharacter.h"

#include "Items/PItem.h"
#include "Items/PItemEquippable.h"
#include "Items/PItemWeapon.h"


// Sets default values for this component's properties
UPInventoryComponent::UPInventoryComponent(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	OwnerCharacter = Cast<APCharacter>(GetOwner());
}

// Called when the game starts
void UPInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

}






///// Items /////

void UPInventoryComponent::AddItem(TSubclassOf<UPItem> Item)
{
	if (!Item)
		return;

	int& ItemCount = Items.FindOrAdd(Item);
	ItemCount++;

	LOG_ACTOR(Log, GetOwner(), "Added item %s", *Item.GetDefaultObject()->Name);

	EquipItem(Item, EPItemSlot::WeaponBack);
}

void UPInventoryComponent::RemoveItem(TSubclassOf<UPItem> Item)
{
	if (!Item)
		return;

	int* ItemCount = Items.Find(Item);
	if (!ItemCount)
	{
		LOG_ACTOR(Warning, GetOwner(), "Attempting to remove item %s, but there are none in this inventory!", *Item.GetDefaultObject()->Name);
		return;
	}

	(*ItemCount)--;
	
	if (*ItemCount <= 0)
		Items.Remove(Item);

	LOG_ACTOR(Log, GetOwner(), "Removed item %s", *Item.GetDefaultObject()->Name);

	UnEquipItem(EPItemSlot::WeaponBack);
}










void UPInventoryComponent::EquipItem(TSubclassOf<UPItem> Item, EPItemSlot Slot)
{
	if (! (
		Item
		&& Item.GetDefaultObject()->bCanBeEquipped
		&& OwnerCharacter))
		return;

	if (EquippedItems.Contains(Slot))
		UnEquipItem(Slot);
		

	Item.GetDefaultObject()->Equip(this, Slot);
}

void UPInventoryComponent::UnEquipItem(EPItemSlot Slot)
{
	if (!OwnerCharacter)
		return;

	FPItemStruct* const EquippedFPItemStruct = EquippedItems.Find(Slot);
	if(EquippedFPItemStruct)
		EquippedFPItemStruct->Item->UnEquip(this, Slot);
}







///// Weapons /////

void UPInventoryComponent::EquipWeapon(UPItemWeapon* Weapon, EPItemSlot Slot)
{
	const EPWeaponType WeaponType = Weapon->WeaponType;
	const FName SocketName = GetWeaponSocket(WeaponType);
	USkeletalMeshComponent* const CharacterMesh = OwnerCharacter->GetMesh();

	AActor* const EquippedActor = SpawnAndAttach(Weapon->EquipItem, CharacterMesh, SocketName);

	FPItemStruct Item;
	Item.Actor = EquippedActor;
	Item.Item = Weapon;

	EquippedItems.Add(Slot, Item);
}

void UPInventoryComponent::UnEquipWeapon(EPItemSlot Slot)
{
	FPItemStruct* const Item = EquippedItems.Find(Slot);

	if (!Item)
		return;

	AActor* const EquippedActor = Item->Actor;
	if (EquippedActor)
	{
		EquippedActor->DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
		EquippedActor->Destroy();
	}

	EquippedItems.Remove(Slot);
}


///// Support /////

FName UPInventoryComponent::GetWeaponSocket(EPWeaponType WeaponType) const
{
	switch (WeaponType)
	{
	case EPWeaponType::Sword1H:
		return "WeaponLeftHandSocket";
	case EPWeaponType::Sword2H:
		return "WeaponHolsterBack01";
	default:
		LOG_ACTOR(Warning, GetOwner(), "Unkown weapon socket");
		return "";
	}
}

AActor* UPInventoryComponent::SpawnAndAttach(UClass* ActorToSpawn, USceneComponent* AttachComponent, FName AttachSocket)
{
	AActor* const SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn);
	
	SpawnedActor->AttachToComponent(AttachComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, AttachSocket);
	
	return SpawnedActor;
}



///// UI /////
TArray<TSubclassOf<UPItem>> UPInventoryComponent::GetItems() const
{
	TArray<TSubclassOf<UPItem>> Result;
	
	Items.GenerateKeyArray(Result);

	return Result;
}

int UPInventoryComponent::GetItemCount(TSubclassOf<UPItem> Item) const
{
	return Items.FindRef(Item);
}
