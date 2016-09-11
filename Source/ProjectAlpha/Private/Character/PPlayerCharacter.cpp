// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PPlayerCharacter.h"


// Sets default values
APPlayerCharacter::APPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	// Interaction
	fMaxInteractDistance = 150;
	FocusedInteractable = nullptr;


	// Initialise components
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->CameraLagSpeed = 3.0f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachToComponent(SpringArm, FAttachmentTransformRules::SnapToTargetIncludingScale);
	Camera->bUsePawnControlRotation = false;

	// Auto possess player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void APPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Get interactable in view
	if (Controller && Controller->IsLocalController())
	{
		UPInteractableComponent* const InteractableInView = GetInteractableInView();

		if (FocusedInteractable != InteractableInView)
		{
			LOG_ACTOR(Log, this, "InteractableInView: %s",
				(InteractableInView) ? *GetDebugName(InteractableInView->GetOwner()) : TEXT("NULL"));

			if (FocusedInteractable)
			{
				LOG_ACTOR(Log, this, "%s->OnEndFocus", *GetDebugName(FocusedInteractable->GetOwner()));
				FocusedInteractable->OnEndFocus();
			}

			FocusedInteractable = InteractableInView;

			if (FocusedInteractable)
			{
				LOG_ACTOR(Log, this, "%s->OnBeginFocus", *GetDebugName(FocusedInteractable->GetOwner()));
				FocusedInteractable->OnBeginFocus();
			}
		}
	}

}

// Called to bind functionality to input
void APPlayerCharacter::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	// Movement
	InputComponent->BindAxis("MoveForward", this, &APPlayerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APPlayerCharacter::MoveRight);

	// Camera
	InputComponent->BindAxis("Turn", this, &APPlayerCharacter::Turn);
	InputComponent->BindAxis("LookUp", this, &APPlayerCharacter::LookUp);

	// Jump
	InputComponent->BindAction("Jump", IE_Pressed, this, &APPlayerCharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &APPlayerCharacter::StopJumping);

	// Interaction
	InputComponent->BindAction("Interact", IE_Pressed, this, &APPlayerCharacter::Interact);
}

void APPlayerCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0)
	{
		const FRotator Rotation = GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);

		AddMovementInput(Direction, Value);
	}

}

void APPlayerCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0)
	{
		const FRotator Rotation = GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);

		AddMovementInput(Direction, Value);
	}
}

void APPlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void APPlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void APPlayerCharacter::Jump()
{
	ACharacter::Jump();
}

void APPlayerCharacter::Interact()
{
	if (FocusedInteractable)
		FocusedInteractable->OnInteract(this);
}

UPInteractableComponent* APPlayerCharacter::GetInteractableInView()
{
	if (!Controller)
		return nullptr;

	FVector CamLoc;
	FRotator CamRot;
	Controller->GetPlayerViewPoint(CamLoc, CamRot);

	const FVector TraceLocationOffset = FVector(0.0f, 0.0f, 50.0f);
	const FRotator TraceRotationOffset = FRotator(10.0f, 0.0f, 0.0f);

	const FVector TraceStart = GetActorLocation() + TraceLocationOffset;
	const FVector TraceDirection = (CamRot + TraceRotationOffset).Vector();
	const FVector TraceEnd = TraceStart + TraceDirection * fMaxInteractDistance;

	FCollisionQueryParams TraceParams(FName("TraceInteractableActor"), true, this);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.bTraceComplex = false;

	FHitResult Hit(ForceInit);

	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Interactable, TraceParams);
	//DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 0.5);

	AActor* const TracedActor = Hit.GetActor();

	if (!TracedActor)
		return nullptr;

	UPInteractableComponent* const InteractableComponent = GET_INTERACTABLE_COMPONENT(TracedActor);

	return InteractableComponent;
}

FString APPlayerCharacter::GetFocusedInteractableName() const
{
	return (FocusedInteractable) ? FocusedInteractable->GetInteractionMessage() : FString();
}


