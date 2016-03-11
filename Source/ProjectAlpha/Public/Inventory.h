// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseItem.h"


/**
 * 
 */
class PROJECTALPHA_API Inventory
{
public:
	Inventory();
	~Inventory();

	void AddItem(ABaseItem* Item);
private:
	TArray<ABaseItem*> Items;
};
