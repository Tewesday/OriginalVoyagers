// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceActor.h"

// Sets default values
AResourceActor::AResourceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AResourceActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AResourceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AResourceActor::ClampAndApplyQuantityChange(int32 ChangeValue) {
	int32 ResourceResult = ChangeValue;
	if (ResourceQuantity - ChangeValue <= 0) {
		ResourceResult = ResourceQuantity;
		ResourceQuantity = 0;
	}
	else {
		ResourceQuantity -= ChangeValue;
	}
	return ResourceResult;
}


