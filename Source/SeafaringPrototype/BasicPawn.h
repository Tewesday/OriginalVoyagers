// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasicRail.h"
#include <Runtime\CinematicCamera\Public\CameraRig_Rail.h>
#include "BasicPawn.generated.h"


UCLASS()
class SEAFARINGPROTOTYPE_API ABasicPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasicPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite)
	ABasicRail* Path;

	UFUNCTION(BlueprintCallable)
	void AssignPath(ABasicRail* PathToAssign);

	UFUNCTION(BlueprintImplementableEvent)
	void ExecuteInstruction();
};
