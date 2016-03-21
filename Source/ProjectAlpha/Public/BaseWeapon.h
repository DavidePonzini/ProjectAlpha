// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseItem.h"
//#include "BaseEquippableActor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class PROJECTALPHA_API ABaseWeapon : public ABaseItem//, public ABaseEquippableActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABaseWeapon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	

	/***** Damage *****/
protected:
	UPROPERTY(EditAnywhere, Category = "Damage")
		float Damage;
//	UPROPERTY(EditAnywhere, Category = "Damage")
//		UDamageType DamageType;
	

public:
	UFUNCTION(BlueprintCallable, Category = "Damage")
		float GetDamage() const;
	UFUNCTION(BlueprintCallable, Category = "Damage")
		void SetDamage(float Value);

};
