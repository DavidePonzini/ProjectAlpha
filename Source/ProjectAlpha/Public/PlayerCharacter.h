// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseCharacter.h"
#include "InteractableActor.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class PROJECTALPHA_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

	/***** COMPONENTS *****/
public:
	// Camera components
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter | Camera")
		USpringArmComponent* SpringArmComp;
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter | Camera")
		UCameraComponent* CameraComp;

/*
	UPROPERTY(EditAnywhere, Category = "ViewCone")
		UStaticMeshComponent* ViewCone;

	UFUNCTION(BlueprintCallable, Category = "TEST")
		UStaticMeshComponent* GetViewCone() const;
*/

public:
	/** Sets default values for this character's properties */
	APlayerCharacter();

	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;
	
	/** Called every frame */
	virtual void Tick(float DeltaSeconds) override;

	/** Called to bind functionality to input */
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	/** Movement */
	void MoveForward(float Value);
	void MoveRight(float Value);
	
	/** Camera */
	void Turn(float Value);
	void LookUp(float Value);

	/** Jump */
	void Jump();

	/* Equip/UnEquip weapons*/
	//void Equip

	/** Death */
	virtual void Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser) override;

	/**** INTERACTION *****/
public:
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		virtual void Interact();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Interaction")
		float fMaxInteractDistance; 

private:
	AInteractableActor* GetInteractableInView();
	AInteractableActor* FocusedInteractable;

	
};
