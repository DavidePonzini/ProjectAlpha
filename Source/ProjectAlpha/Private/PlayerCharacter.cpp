// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PlayerCharacter.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	// Interaction
	fMaxInteractDistance = 400;
	FocusedInteractable = nullptr;


	// Initialise components
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->AttachTo(RootComponent);
	SpringArmComp->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bEnableCameraLag = false;
	SpringArmComp->CameraLagSpeed = 3.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->AttachTo(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;

/*
	ViewCone = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ViewCone"));
	ViewCone->AttachTo(CameraComp);
*/

	// Auto possess player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	//Get interactable in view
	if (Controller && Controller->IsLocalController())
	{
		AInteractableActor* InteractableInView = GetInteractableInView();

		if (FocusedInteractable != InteractableInView)
		{
			if (FocusedInteractable)
				FocusedInteractable->EndFocus(this);
			
			FocusedInteractable = InteractableInView;

			if (FocusedInteractable)
				FocusedInteractable->BeginFocus(this);
		}
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	// Movement
	InputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	// Camera
	InputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	InputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);

	// Jump
	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Interaction
	InputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);
}

void APlayerCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0)
	{
		const FRotator Rotation = GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);

		AddMovementInput(Direction, Value);
	}

}

void APlayerCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0)
	{
		const FRotator Rotation = GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void APlayerCharacter::Jump()
{
	ACharacter::Jump();
}

void APlayerCharacter::Interact()
{
	if(FocusedInteractable)
		FocusedInteractable->Interact(this);
}

/*
UStaticMeshComponent* APlayerCharacter::GetViewCone() const
{
	return ViewCone;
}
*/

AInteractableActor* APlayerCharacter::GetInteractableInView()
{
	if(!Controller)
		return NULL;

	const float TraceRadius = 150;
	const enum EObjectTypeQuery TraceObject = ObjectTypeQuery1;

	FVector CamLoc;
	FRotator CamRot;
	Controller->GetPlayerViewPoint(CamLoc, CamRot);
	
	const FVector TraceStart = CamLoc;
	const FVector TraceDirection = CamRot.Vector();
	const FVector TraceOffset = FVector(SpringArmComp->TargetArmLength + TraceRadius);
	const FVector TraceCentre = TraceStart + TraceDirection * TraceOffset;

	FCollisionQueryParams TraceParams(FName("TraceInteractableActor"), true, this);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.bTraceComplex = false;

//	TArray<FHitResult> Hits;
	FHitResult Hit(ForceInit);

//	DrawDebugSphere(GetWorld(), TraceStart, TraceRadius, 8, FColor::Cyan, false, 0.05);
//	DrawDebugSphere(GetWorld(), TraceCentre, TraceRadius, 8, FColor::Blue, false, 0.05);
//	GetWorld()->SweepMultiByObjectType(Hits, TraceStart, TraceCentre, FQuat(), TraceObject, FCollisionShape::MakeSphere(TraceRadius), TraceParams);
//	UE_LOG(LogTemp, Warning, TEXT("--> %p"), Hit.GetActor());
//	return Cast<AInteractableActor>(Hit.GetActor());
	GetWorld()->SweepSingleByChannel(Hit, TraceCentre, TraceCentre+TraceDirection, FQuat(), ECC_Interactable, FCollisionShape::MakeSphere(TraceRadius), TraceParams);

	return Cast<AInteractableActor>(Hit.GetActor());

/*	AInteractableActor* ia;
	int i = 0;
	for (FHitResult hit : Hits)
	{
		ia = Cast<AInteractableActor>(hit.GetActor());

		if (ia)
		{
			// Perform line trace to check if object is actually visible
			UE_LOG(LogTemp, Warning, TEXT(">>> %d"), i);
			return ia;
		}
		i++;
	}

	return nullptr;
*/	
/*
	TArray<AActor*> actors;
	ViewCone->GetOverlappingActors(actors, AInteractableActor::StaticClass());

	AInteractableActor* ia;
	for (AActor* actor : actors)
	{
		ia = Cast<AInteractableActor>(actor);

		if (ia)
		{
			// Perform line trace to check if object is visible
			return ia;
		}
	}

	return nullptr;

*/
/*	const FVector TraceStart = CamLoc + FVector(0.0f, 0.0f, -50.0f);
	const FVector TraceDirection = (CamRot + FRotator(15.0f, 0.0f, 0.0f)).Vector();
	const FVector TraceEnd = TraceStart + TraceDirection * fMaxInteractDistance;

	FCollisionQueryParams TraceParams(FName("TraceInteractableActor"), true, this);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.bTraceComplex = false;

	TArray<FHitResult> Hits;
//	FHitResult Hit(ForceInit);
//	GetWorld()->Sweep
	GetWorld()->SweepMultiByObjectType(Hits, TraceStart, TraceEnd, FQuat(), ECC_Visibility, FCollisionShape::MakeSphere(150), TraceParams);

	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Yellow, false, 0.05);
	DrawDebugSphere(GetWorld(), TraceEnd, 150, 6, FColor::Blue);
//	const FString name = GetDebugName(Hit.GetActor());
//	DrawDebugString(GetWorld(), TraceEnd, name, nullptr, FColor::White, 0.01);
/*
//	GetWorld()->LineTraceSingle(Hit, TraceStart, TraceEnd, ECC_Visibility, TraceParams);
	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility, TraceParams);
//	GetWorld()->

	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Green, false, 0.2);
//	DrawDebugCone(GetWorld(), TraceStart, TraceDirection, fMaxInteractDistance, 0.349066, 0.349066, 4, FColor::Yellow, false, 0.2);
	DrawDebugSphere(GetWorld(), CamLoc + CamRot.Vector() * fMaxInteractDistance, 150, 8, FColor::Blue, false, 0.2);
*/
/*	AInteractableActor* ia = nullptr;
	int r = rand();
	for (FHitResult result : Hits)
	{
		ia = Cast<AInteractableActor>(result.GetActor());
		UE_LOG(LogTemp, Warning, TEXT("%d - Cast to IA: %p"), r, ia);
		if (ia)
		{
			UE_LOG(LogTemp, Error, TEXT("%d - Cast to IA: %s"), r, *GetDebugName(ia));
			return ia;
		}
	}
	return nullptr;
*/
}

void APlayerCharacter::Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser)
{
	Super::Die(KillingDamage, DamageEvent, Killer, DamageCauser);
}