// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ResourceActor.generated.h"

UCLASS()
class SEAFARINGPROTOTYPE_API AResourceActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResourceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
	FString ResourceType;

	UPROPERTY(BlueprintReadWrite)
	int32 ResourceQuantity;

	UFUNCTION(BlueprintCallable)
	int32 ClampAndApplyQuantityChange(int32 ChangeValue);

};
