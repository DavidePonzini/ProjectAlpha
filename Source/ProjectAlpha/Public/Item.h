// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EquippableActor.h"
//#include "BaseCharacter.h"
	class ABaseCharacter;
//#include "PickupActor.h"
	class APickupActor;
#include "Types.h"
#include "Item.generated.h"

/**
*
*/

UCLASS(abstract, Blueprintable)
class PROJECTALPHA_API UItem : public UObject
{
	GENERATED_BODY()

public:
	UItem();
	~UItem();

	UPROPERTY(EditAnywhere, Category = "Inventory")
		TSubclassOf<AEquippableActor> EquippableActor;
	UPROPERTY(EditAnywhere, Category = "Inventory")
		TSubclassOf<APickupActor> PickupActor;

	void Equip(ABaseCharacter* WhoEquipped);
	void UnEquip();

	void Drop();

	bool bIsEquipped;
	APawn* WhoIsEquipping;

	/***** PRICE ****/
/*
	protected:
	UPROPERTY(EditAnywhere, Category = "Price")
	TArray<int64> Price;

	public:
	UFUNCTION(BlueprintCallable, Category = "Price")
	bool CanAfford(APawn* Buyer) const;

	UFUNCTION(BlueprintCallable, Category = "Price")
	void SetPrice(int64 Value, ECurrencyType CurrencyType);

	UFUNCTION(BlueprintCallable, Category = "Price")
	int64 GetPrice(ECurrencyType CurrencyType) const;
*/
};
