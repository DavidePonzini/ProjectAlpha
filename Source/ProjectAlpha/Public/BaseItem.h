// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseEquippableActor.h"
//#include "PickupActor.h"
#include "Types.h"
#include "BaseItem.generated.h"

/**
*
*/

UCLASS(Blueprintable)
class PROJECTALPHA_API UBaseItem : public UObject
{
	GENERATED_BODY()

public:
	UBaseItem();
	~UBaseItem();

	UPROPERTY(EditAnywhere, Category = "Inventory")
		TSubclassOf<ABaseEquippableActor> EquippableActor;
	//	UPROPERTY(EditAnywhere, Category = "Inventory")
	//		TSubclassOf<APickupActor> PickupActor;

	void Equip(APawn* WhoEquipped);
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
