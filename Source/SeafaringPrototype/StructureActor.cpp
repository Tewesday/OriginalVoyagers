// Fill out your copyright notice in the Description page of Project Settings.


#include "StructureActor.h"

// Sets default values
AStructureActor::AStructureActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStructureActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStructureActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AStructureActor::CalculateResourceCollection() {
	int32 ResourcesCollected = Workers.Num() * StructureQuality;
	return ResourcesCollected;
}

