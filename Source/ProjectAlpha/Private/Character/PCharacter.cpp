// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "Character/PCharacter.h"


// Sets default values
APCharacter::APCharacter()
{
	Stats = CreateDefaultSubobject<UPStatsComponent>(TEXT("Character Stats"));
	Inventory = CreateDefaultSubobject<UPInventoryComponent>(TEXT("Character Inventory"));

}

