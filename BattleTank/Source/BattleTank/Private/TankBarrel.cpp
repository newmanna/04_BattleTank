// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::MoveTo(float Pitch) {

	// move the barrel the right amount this frame
	// given a max elevation speed, and the frame time

	// auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	Pitch = FMath::Clamp<float>(Pitch, -1, 1);
	auto ElevationChange = Pitch * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
		SetRelativeRotation(FRotator(Elevation, 0, 0));
}

