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

// Iterates through an array of actors and returns the first one that implements the Interactable interface.
AActor* APlayerCharacter::FindInteractableInArray(TArray<AActor*> &Actors)
{
	// Iterate and return the first one that implements the Interactable interface.
	for (int i=0; i<Actors.Num(); i++)
	{
		if(Actors[i]->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{
			return Actors[i];
		}
	}

	// If we get here, we didn't find any interactable actors.
	return nullptr;
}

// Attempts to find the first interactable actor that the player is overlapping with.
AActor* APlayerCharacter::FindInteractable(EInteractableFinder& InteractableFinder)
{
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors);

	AActor* Interactable = FindInteractableInArray(OverlappingActors);
	
	if (Interactable == nullptr)
	{
		InteractableFinder = EInteractableFinder::NotFound;
	}
	else
	{
		InteractableFinder = EInteractableFinder::Found;
	}
	
	return Interactable;

}

// Attempts to find the first interactable actor that the player is overlapping with that is of the specified class.
AActor* APlayerCharacter::FindInteractableByClass(EInteractableFinder& InteractableFinder,
	TSubclassOf<AActor> InteractableClass)
{
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors, InteractableClass);

	AActor* Interactable = FindInteractableInArray(OverlappingActors);
	
	if (Interactable == nullptr)
	{
		InteractableFinder = EInteractableFinder::NotFound;
	}
	else
	{
		InteractableFinder = EInteractableFinder::Found;
	}
	
	return Interactable;
}

