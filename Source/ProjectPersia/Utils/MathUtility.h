// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MathUtility.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTPERSIA_API UMathUtility : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Returns the angle between two vectors in degrees
	 * @param A The first vector
	 * @param B The second vector
	 * @return The angle between the two vectors in degrees
	 */
	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Vectors Utility")
	static UPARAM(DisplayName="Angle in deg") float AngleBetweenVectors(FVector A, FVector B);
};
