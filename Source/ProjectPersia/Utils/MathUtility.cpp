// Fill out your copyright notice in the Description page of Project Settings.


#include "MathUtility.h"

#include "Kismet/KismetMathLibrary.h"

// Returns the angle between two vectors in degrees
float UMathUtility::AngleBetweenVectors(const FVector A, const FVector B)
{
	// Normalize vectors so magnitude is 1
	const FVector NormalizedA = A.GetSafeNormal();
	const FVector NormalizedB = B.GetSafeNormal();

	// Dot product of normalized vectors will give us the cos of the angle between them
	const float Dot = FVector::DotProduct(NormalizedA, NormalizedB);

	// Use acos to cancel cos and get angle in degrees
	return UKismetMathLibrary::DegAcos(Dot);;
}
