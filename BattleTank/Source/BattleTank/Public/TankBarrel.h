// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20; // sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 30.; 
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0.; 


};