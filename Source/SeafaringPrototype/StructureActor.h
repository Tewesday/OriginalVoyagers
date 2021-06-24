// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StructureActor.generated.h"

UCLASS()
class SEAFARINGPROTOTYPE_API AStructureActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStructureActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FString StructureType;

	UPROPERTY(BlueprintReadWrite)
	int32 StructureCost;

	UPROPERTY(BlueprintReadWrite)
	FString ResourceType;

	UPROPERTY(BlueprintReadWrite)
	FString OwningRegion;

	UPROPERTY(BlueprintReadWrite)
	TSet<AActor*> Workers;

	UPROPERTY(BlueprintReadWrite)
	int32 MaxWorkers;

	UPROPERTY(BlueprintReadWrite)
	int32 StructureQuality;

	UFUNCTION(BlueprintCallable)
	int32 CalculateResourceCollection();

};
