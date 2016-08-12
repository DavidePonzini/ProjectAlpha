// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "CharacterStats.h"

FStatData::FStatData()
{
	Max = 0.0f;
	Current = 0.0f;
	Buff = 0.0f;
}

UCharacterStats::UCharacterStats(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

ICharacterStats::ICharacterStats()
{
}

float ICharacterStats::GetStatMax(EStatValue stat) const
{
	return Stats[stat].Max;
}

float ICharacterStats::GetStat(EStatValue stat) const
{
	return Stats[stat].Current;
}

float ICharacterStats::GetStatBuff(EStatValue stat) const
{
	return Stats[stat].Buff;
}

void ICharacterStats::ChangeStatMax(EStatValue stat, float amount)
{
	FStatData* FStatData = &Stats[stat];
	
	FStatData->Max += amount;
	
	if (FStatData->Max < 0)
		FStatData->Max = 0;
}

void ICharacterStats::ChangeStat(EStatValue stat, float amount)
{
	FStatData* FStatData = &Stats[stat];
	FStatData->Current = FMath::Clamp(FStatData->Current + amount, 0.0f, FStatData->Max);
}

void ICharacterStats::ChangeStatBuff(EStatValue stat, float amount)
{
	Stats[stat].Buff += amount;
}

void ICharacterStats::ClearStatBuff(EStatValue stat)
{
	Stats[stat].Buff = 0.0f;
}
