// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "ItemData.generated.h"


/**
 * 
 */

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "ItemData")
		FName Name;
	UPROPERTY(EditAnywhere, Category = "ItemData")
		UTexture2D* InventoryImage;
	UPROPERTY(EditAnywhere, Category = "ItemData")
		int32 Price;
};
