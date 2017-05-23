// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; // forward declaration
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();
protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	// UClass* ProjectileBlueprint; // alternative https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; // TODO find sensible default

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSecs = 3;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; // TODO remove

	double LastFireTime = 0;
};
