// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "CharacterStats.h"

// Sets default values for this component's properties
UCharacterStats::UCharacterStats()
	: Super()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UCharacterStats::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UCharacterStats::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UCharacterStats::GetStatMax(EStatValue stat) const
{
	switch (stat)
	{
	case EStatValue::Health:
		return Health.Max;
	case EStatValue::Ki:
		return Ki.Max;
	case EStatValue::Stamina:
		return Stamina.Max;
	default:
		LOG(Warning, "CharacterStats", "GetStatMax() -- invalid value %d", (int)stat);
		return 0.0f;
	}
}

float UCharacterStats::GetStat(EStatValue stat) const
{
	switch (stat)
	{
	case EStatValue::Health:
		return Health.Current;
	case EStatValue::Ki:
		return Ki.Current;
	case EStatValue::Stamina:
		return Stamina.Current;
	default:
		LOG(Warning, "CharacterStats", "GetStat() -- invalid value %d", (int)stat);
		return 0.0f;
	}
}

float UCharacterStats::GetStatBuff(EStatValue stat) const
{
	return 0.0f;
}

void UCharacterStats::ChangeStatMax(EStatValue stat, float amount)
{
	
}

void UCharacterStats::ChangeStat(EStatValue stat, float amount)
{
	
}

void UCharacterStats::ChangeStatBuff(EStatValue stat, float amount)
{
	
}

void UCharacterStats::ClearStatBuff(EStatValue stat)
{
	
}
