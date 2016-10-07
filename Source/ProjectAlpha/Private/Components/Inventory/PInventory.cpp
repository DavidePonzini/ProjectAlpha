// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PInventory.h"

/*
template<class T>
bool PInventoryCategory<T>::AddItemStackable(T* Item)
{
	int& Amount = Items.FindOrAdd(Item);

	Amount++;

	return true;
}

template<class T>
bool PInventoryCategory<T>::AddItemNotStackable(T* Item)
{
	T* NewItem = DuplicateObject<T>(Item, nullptr);

	Items.Add(NewItem, 1);

	return true;
}

template<class T>
bool PInventoryCategory<T>::AddItem(TSubclassOf<T> ItemClass)
{
	T* const Item = ItemClass.GetDefaultObject();

	if (Item->IsStackable())
		return AddItemStackable(Item);
	else
		return AddItemNotStackable(Item);
}

template <class T>
bool PInventory<T>::AddItem(TSubclassOf<T> ItemClass)
{
	T* const Item = ItemClass.GetDefaultObject();

	const int CategoryIdx = Item->GetCategory();

	return Categories[CategoryIdx].AddItem(ItemClass);
}

template <class T>
void PInventory<T>::Init(int Size)
{
	Categories.AddDefaulted(Size);
}
*/