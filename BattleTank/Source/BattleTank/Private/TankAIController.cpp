// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAITank();
	if (!AIControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(AIControlledTank->GetName()));
	}
}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}




