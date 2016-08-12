#pragma once

#include "UObject.h"
#include "CharacterStats.generated.h"

/** Module for Character Stats.
 * TODO -- add buff/debuff support
 */

 // Category definitions for UPROPERTIES / UFUNCTIONS
#define CAT_NAME "Stats"

 // Stat type definitions
UENUM(BlueprintType)
enum EStatValue
{
	Health,
	Ki,
	Stamina,
	NO_ELEMS
};

USTRUCT()
struct FStatData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Stats")
		float Max;
	UPROPERTY(EditAnywhere, Category = "Stats")
		float Current;
	UPROPERTY(EditAnywhere, Category = "Stats")
		float Buff;

	FStatData();
};

UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UCharacterStats : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class ICharacterStats : public UActorComponent
{
	GENERATED_IINTERFACE_BODY()

protected:
	ICharacterStats();

// Values
protected:
	FStatData Stats[EStatValue::NO_ELEMS];

// Getters
public:

	UFUNCTION(BlueprintCallable, Category = CAT_NAME)
		virtual float GetStatMax(EStatValue stat) const;
	UFUNCTION(BlueprintCallable, Category = CAT_NAME)
		virtual float GetStat(EStatValue stat) const;
	UFUNCTION(BlueprintCallable, Category = CAT_NAME)
		virtual float GetStatBuff(EStatValue stat) const;

// Setters
public:
	// Changers -- increment or decrement a stat
	UFUNCTION(BlueprintCallable, Category = CAT_NAME)
		virtual void ChangeStatMax(EStatValue stat, float amount);
	UFUNCTION(BlueprintCallable, Category = CAT_NAME)
		virtual void ChangeStat(EStatValue stat, float amount);
	UFUNCTION(BlueprintCallable, Category = CAT_NAME)
		virtual void ChangeStatBuff(EStatValue stat, float amount);

	// Clear buffs
	UFUNCTION(BlueprintCallable, Category = CAT_NAME)
		virtual void ClearStatBuff(EStatValue stat);


/*				ARE THESE NEEDED?

	// Setters -- set directly a stat
	UFUNCTION(BlueprintCallable, Category = CAT_NAME)
		void SetStatMax(EStatValue stat, float amount);
	UFUNCTION(BlueprintCallable, Category = CAT_NAME)
		void SetStat(EStatValue stat, float amount);
*/
};
