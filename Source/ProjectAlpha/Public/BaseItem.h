// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Types.h"
#include "BaseItem.generated.h"

UCLASS(ABSTRACT)
class PROJECTALPHA_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Equipping")
		EInventorySlot Slot;
	EInventorySlot GetInventorySlot();

	/***** COMPONENTS *****/
protected:
	UPROPERTY(EditAnywhere, Category = "Mesh")
		UMeshComponent* Mesh;


	/***** PRICE ****/
protected:
	UPROPERTY(EditAnywhere, Category = "Price")
		int32 PriceGold;
	UPROPERTY(EditAnywhere, Category = "Price")
		int32 PriceSilver;
	UPROPERTY(EditAnywhere, Category = "Price")
		int32 PriceBronze;

public:
	UFUNCTION(BlueprintCallable, Category = "Price")
		bool CanAfford(APawn* Buyer) const;

	UFUNCTION(BlueprintCallable, Category = "Price")
		void SetPriceGold(int32 Value);
	UFUNCTION(BlueprintCallable, Category = "Price")
		void SetPriceSilver(int32 Value);
	UFUNCTION(BlueprintCallable, Category = "Price")
		void SetPriceBronze(int32 Value);

	UFUNCTION(BlueprintCallable, Category = "Price")
		int32 GetPriceGold() const;
	UFUNCTION(BlueprintCallable, Category = "Price")
		int32 GetPriceSilver() const;
	UFUNCTION(BlueprintCallable, Category = "Price")
		int32 GetPriceBronze() const;	
};
