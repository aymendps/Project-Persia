// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

enum class EInteractableFinder : uint8;

UCLASS()
class PROJECTPERSIA_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Iterates through an array of actors and returns the first one that implements the Interactable interface.
	UFUNCTION()
	AActor* FindInteractableInArray(TArray<AActor*> &Actors);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**
	 * Attempts to find the first interactable actor that the player is overlapping with.
	 * @return The first interactable actor that the player is overlapping with.
	 */
	UFUNCTION(BlueprintCallable, Category="Interactable", Meta=(ExpandEnumAsExecs="InteractableFinder"))
	AActor* FindInteractable(EInteractableFinder& InteractableFinder);

	/**
	 * Attempts to find the first interactable actor that the player is overlapping with that is of the specified class.
	 * @return The first interactable actor that the player is overlapping with that is of the specified class.
	 */
	UFUNCTION(BlueprintCallable, Category="Interactable", Meta=(ExpandEnumAsExecs="InteractableFinder"))
	AActor* FindInteractableByClass(EInteractableFinder& InteractableFinder, TSubclassOf<AActor> InteractableClass);
};
