// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "ProjectPersia/Interfaces/Interactable.h"
#include "ProjectPersia/Enums/EInteractableFinder.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

AActor* APlayerCharacter::FindInteractable(EInteractableFinder& InteractableFinder)
{
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors);

	// Iterate and return the first one that implements the Interactable interface.
	for (int i=0; i<OverlappingActors.Num(); i++)
	{
		if(OverlappingActors[i]->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{
			InteractableFinder = EInteractableFinder::Found;
			return OverlappingActors[i];
		}
	}

	// If we get here, we didn't find any interactable actors.
	InteractableFinder = EInteractableFinder::NotFound;
	return nullptr;
}

