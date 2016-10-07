// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PInventoryComponent.h"

#include "PCharacter.h"


// Sets default values for this component's properties
UPInventoryComponent::UPInventoryComponent(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	OwnerCharacter = Cast<APCharacter>(GetOwner());

	Inventory.Init(EPItemCategory::NO_ELEMS);
}

// Called when the game starts
void UPInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

}

///// Items /////

void UPInventoryComponent::AddItem(TSubclassOf<UPItem> ItemClass)
{
	if (!ItemClass)
		return;

	Inventory.AddItem(ItemClass);
	
	//LOG_ACTOR(Log, GetOwner(), "Added item %s", *Item->Name);

//	EquipItem(Item, EPItemSlot::WeaponBack);
}

void UPInventoryComponent::RemoveItem(UPItem* Item)
{
	if (!Item)
		return;
}

void UPInventoryComponent::EquipItem(UPItem* Item, EPItemSlot Slot)
{
	if (! (
		Item
		&& Item->bCanBeEquipped
		&& OwnerCharacter))
		return;

	if (EquippedItems.Contains(Slot))
		UnEquipItem(Slot);
		

	Item->Equip(this, Slot);
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
/*
int UPInventoryComponent::GetItemCount(UPItem* Item) const
{
	return Inventory.GetItemCount(Item);
}
*/
