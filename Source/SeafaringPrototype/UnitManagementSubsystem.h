// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "BasicPawn.h"
#include <Runtime\CinematicCamera\Public\CameraRig_Rail.h>
#include "UnitManagementSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class SEAFARINGPROTOTYPE_API UUnitManagementSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_DELEGATE(FunctionDelegate);

	
public:

	UPROPERTY(BlueprintReadWrite)
	TArray<ABasicPawn*> Units;

	/*UPROPERTY(BlueprintReadWrite)
	ACameraRig_Rail* Path;*/

	UFUNCTION(BlueprintCallable)
	void AddSelection(TArray<ABasicPawn*> SelectionToAdd);

	UFUNCTION(BlueprintCallable)
	void RemoveSelection();

	/*UFUNCTION(BlueprintCallable)
	void AssignPathToUnits();*/

	UFUNCTION(BlueprintCallable)
	void AssignPathToUnits(ACameraRig_Rail* PathToAssign);

	UFUNCTION(BlueprintCallable)
	void InstructUnits();

	//UFUNCTION(BlueprintCallable)
	//void InstructUnits(FunctionDelegate InstructionFunction);
};
