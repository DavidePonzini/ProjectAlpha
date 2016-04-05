// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseItem.h"
#include "BaseCharacter.generated.h"

UCLASS(abstract)
class PROJECTALPHA_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/** Sets default values for this character's properties */
	ABaseCharacter();

	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;


	/***** STATS *****/
public:
	/** Maximum allowed value of Health, represents full health */
	UPROPERTY(EditAnywhere, Category = "Stats")
		float MaxHealth;
protected:
	/** Current health */
	UPROPERTY()
		float Health;

public:
	UFUNCTION(BlueprintCallable, Category = "Stats|Health")
		float GetMaxHealth() const;
	UFUNCTION(BlueprintCallable, Category = "Stats|Health")
		float GetHealth() const;

	/***** STATS CHANGES *****/
public:
	UFUNCTION(BlueprintCallable, Category = "Stats|Health")
		virtual float RestoreHealth(float Amount);

	/** Take Damage */
	UFUNCTION(BlueprintCallable, Category = "Damage")
		virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* WhoDamaged, AActor* DamageCauser) override;


	/***** DEATH *****/	
	/** Called when this actor dies */
	UFUNCTION(BlueprintCallable, Category = "Death")
		virtual void Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser);

	/** Handle character getting out of world */
	UFUNCTION(BlueprintCallable, Category = "OutOfWorld")
		virtual void OutOfWorld();


	/***** INVENTORY *****/
protected:
	FName GetHandAttachPoint(EEquipSlot Slot) const;
	FName GetBackAttachPoint(EEquipSlot Slot) const;

protected:
	TArray<UBaseItem*> Inventory;

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		virtual void AddItem(UBaseItem* Item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		virtual void RemoveItem(UBaseItem* Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		virtual void EquipItem(UBaseItem* Item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		virtual void UnEquipItem(UBaseItem* Item);
	/*
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		virtual void SheathItem(UBaseItem* Item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		virtual void UnSheathItem(UBaseItem* Item);
	*/
};
