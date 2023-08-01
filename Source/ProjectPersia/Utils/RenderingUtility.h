// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RenderingUtility.generated.h"

/**
 * Class containing static rendering utility functions that can be used in blueprints
 */
UCLASS()
class PROJECTPERSIA_API URenderingUtility : public UObject
{
	GENERATED_BODY()

	/**
	 * Returns whether the actor is on the viewport or not
	 * @param Actor The actor to check
	 * @return Whether the actor is on the viewport or not
	 */
	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Viewport Utility")
	static bool IsOnViewport(AActor* Actor); 
};
