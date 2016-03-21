// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Types.generated.h"


UENUM()
enum class ECurrencyType : uint8
{
	Gold,
	Silver,
	Bronze,
	_NO_ELEMS,
};

UENUM()
enum class EEquipSlot : uint8
{
	NONE,
	WeaponBack01,
	WeaponBack02,

};

UENUM()
enum class EItemType : uint8
{
	NONE,
};