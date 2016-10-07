// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ProjectAlpha.h"


template <class T>
class PInventoryCategory
{
private:
	TMap<T*, int> Items;

private:
	bool AddItemStackable(T* Item)
	{
		int& Amount = Items.FindOrAdd(Item);

		Amount++;

		return true;
	}

	bool AddItemNotStackable(T* Item)
	{
		T* NewItem = DuplicateObject<T>(Item, nullptr);

		Items.Add(NewItem, 1);

		return true;
	}

public:
	bool AddItem(TSubclassOf<T> ItemClass)
	{
		T* const Item = ItemClass.GetDefaultObject();

		if (Item->IsStackable())
			return AddItemStackable(Item);
		else
			return AddItemNotStackable(Item);
	}

	FORCEINLINE TArray<T*> GetItems() const
	{
		TArray<T*> Result;

		Items.GenerateKeyArray(Result);

		return Result;
	}

	FORCEINLINE int GetItemCount(T* Item) const
	{
		return Items.FindRef(Item);
	}
};

template <class T>
class PInventory
{
private:
	TArray<PInventoryCategory<T>> Categories;

public:
	void Init(int Size)
	{
		Categories.AddDefaulted(Size);
	}

	bool AddItem(TSubclassOf<T> ItemClass)
	{
		T* const Item = ItemClass.GetDefaultObject();

		int CategoryIdx = Item->GetCategory();

		return Categories[CategoryIdx].AddItem(ItemClass);
	}

	FORCEINLINE TArray<T*> GetItems(int Category) const
	{
		return Categories[Category].GetItems();
	}
	
	int GetItemCount(T* Item) const
	{
		int CategoryIdx = Item->GetCategory();
		return Categories[CategoryIdx].GetItemCount(Item);
	}
};
