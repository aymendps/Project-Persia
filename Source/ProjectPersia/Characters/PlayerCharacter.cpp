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
	
	if (OverlappingActors.Num() > 0)
	{
		if(OverlappingActors[0]->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{
			InteractableFinder = EInteractableFinder::Found;
			return OverlappingActors[0];
		}
		
		InteractableFinder = EInteractableFinder::NotFound;
		return nullptr;
		
	}
	
	InteractableFinder = EInteractableFinder::NotFound;
	return nullptr;
}

