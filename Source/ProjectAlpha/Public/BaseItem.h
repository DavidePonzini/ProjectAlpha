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
		EEquipSlot Slot;
	EEquipSlot GetEquipSlot();

	/***** COMPONENTS *****/
protected:
	UPROPERTY(EditAnywhere, Category = "Mesh")
		UMeshComponent* Mesh;


	/***** PRICE ****/
protected:
	UPROPERTY(EditAnywhere, Category = "Price")
		TArray<int64> Price;

public:
	UFUNCTION(BlueprintCallable, Category = "Price")
		bool CanAfford(APawn* Buyer) const;
/*
	UFUNCTION(BlueprintCallable, Category = "Price")
		void SetPrice(int64 Value, ECurrencyType CurrencyType);

	UFUNCTION(BlueprintCallable, Category = "Price")
		int64 GetPrice(ECurrencyType CurrencyType) const;
	*/
};
