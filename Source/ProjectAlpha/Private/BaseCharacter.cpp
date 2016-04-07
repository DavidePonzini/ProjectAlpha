// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
}

float ABaseCharacter::RestoreHealth(float Amount)
{
	Health = FMath::Clamp(Health + Amount, 0.0f, MaxHealth);

	return Health;
}

void ABaseCharacter::Die(float KillingDamage, FDamageEvent const & DamageEvent, AController * Killer, AActor * DamageCauser)
{
	EndPlay(EEndPlayReason::Destroyed);

	RootComponent->SetWorldLocation(FVector(0, 0, 108));

	BeginPlay();
}

void ABaseCharacter::OutOfWorld()
{
	RootComponent->SetWorldLocation(FVector(0, 0, 108));
}

void ABaseCharacter::AddItem(UItem* Item)
{
	if (!Item)
		return;

	EquipItem(Item);
}

void ABaseCharacter::RemoveItem(UItem* Item)
{
	if (!Item)
		return;

	UnEquipItem(Item);
}
/*
FName ABaseCharacter::GetAttachPoint(EEquipSlot Slot)
{
	switch (Slot)
	{
	case EEquipSlot::Back01:
		return "WeaponHolsterBack01";
	case EEquipSlot::Back02:
		return "WeaponHolsterBack02";
	case EEquipSlot::Hand:
		return "WeaponHand";
	default:
		// Not implemented
		return "";
	}
}
*/
FName ABaseCharacter::GetHandAttachPoint(EEquipSlot Slot) const
{
	switch (Slot)
	{
	case EEquipSlot::WeaponBack01:
	case EEquipSlot::WeaponBack02:
		return "WeaponHand";
	default:
		// Not implemented
		return "";
	}
}

FName ABaseCharacter::GetBackAttachPoint(EEquipSlot Slot) const
{
	switch (Slot)
	{
	case EEquipSlot::WeaponBack01:
		return "WeaponHolsterBack01";
	case EEquipSlot::WeaponBack02:
		return "WeaponHolsterBack02";
	default:
		// Not implemented
		return "";
	}
}

void ABaseCharacter::EquipItem(UItem* Item)
{
	if (!Item)
		return;

	Weapon1 = GetWorld()->SpawnActor<AEquippableActor>(Item->EquippableActor);

	const EEquipSlot EquipSlot = EEquipSlot::WeaponBack01;
	if (EquipSlot == EEquipSlot::NONE)
		return;

	Weapon1->SetActorHiddenInGame(false);
	Weapon1->AttachRootComponentTo(GetMesh(), GetBackAttachPoint(EquipSlot), EAttachLocation::SnapToTarget);

}

void ABaseCharacter::UnEquipItem(UItem* Item)
{
	if (!Weapon1)
		return;

	Weapon1->DetachRootComponentFromParent();
	Weapon1->SetActorHiddenInGame(true);

}

float ABaseCharacter::GetMaxHealth() const
{
	return MaxHealth;
}

float ABaseCharacter::GetHealth() const
{
	return Health;
}

float ABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* Instigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, Instigator, DamageCauser);

	Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);

	if (Health <= 0)
	{
		Die(DamageAmount, DamageEvent, Instigator, DamageCauser);
	}

	return Health;
}
/*
void ABaseCharacter::SheathItem(ABaseItem * Item)
{
	if (!Item)
		return;

	const EEquipSlot EquipSlot = Item->GetEquipSlot();
	if (EquipSlot == EEquipSlot::NONE)
		return;
	
	Item->DetachRootComponentFromParent();
	Item->AttachRootComponentTo(Mesh, GetBackAttachPoint(EquipSlot), EAttachLocation::SnapToTarget);
}

void ABaseCharacter::UnSheathItem(ABaseItem * Item)
{
	if (!Item)
		return;

	const EEquipSlot EquipSlot = Item->GetEquipSlot();
	if (EquipSlot == EEquipSlot::NONE)
		return;

	Item->DetachRootComponentFromParent();
	Item->AttachRootComponentTo(Mesh, GetHandAttachPoint(EquipSlot), EAttachLocation::SnapToTarget);
}
*/

