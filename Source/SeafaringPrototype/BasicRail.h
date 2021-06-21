// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicRail.generated.h"

class USplineComponent;
class USplineMeshComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS()
class SEAFARINGPROTOTYPE_API ABasicRail : public AActor
{
	GENERATED_BODY()
	
public:
	// ctor
	ABasicRail(const FObjectInitializer& ObjectInitialier);

	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldTickIfViewportsOnly() const override;

	/** Defines current position of the mount point along the rail, in terms of normalized distance from the beginning of the rail. */
	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, Category = "Rail Controls", meta = (ClampMin = "0.0", ClampMax = "1.0"))
		float CurrentPositionOnRail;

	/** Determines whether the orientation of the mount should be in the direction of the rail. */
	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, Category = "Rail Controls")
		bool bLockOrientationToRail;

#if WITH_EDITORONLY_DATA
	/** Determines whether or not to show the rail mesh preview. */
	UPROPERTY(Transient, EditAnywhere, Category = "Rail Controls")
		bool bShowRailVisualization;

	/** Determines the scale of the rail mesh preview */
	UPROPERTY(Transient, EditAnywhere, Category = "Rail Controls")
		float PreviewMeshScale;
#endif

	virtual class USceneComponent* GetDefaultAttachComponent() const override;
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditUndo() override;
	virtual void PostEditMove(bool bFinished) override;
#endif

	/** Returns the spline component that defines the rail path */
	UFUNCTION(BlueprintPure, Category = "Rail Components")
		USplineComponent* GetRailSplineComponent() { return RailSplineComponent; }

private:
	/** Makes sure all components are arranged properly. Call when something changes that might affect components. */
	void UpdateRailComponents();
#if WITH_EDITORONLY_DATA
	void UpdatePreviewMeshes();
#endif
	USplineMeshComponent* CreateSplinePreviewSegment();

	/** Root component to give the whole actor a transform. */
	UPROPERTY(EditDefaultsOnly, Category = "Rail Components")
		USceneComponent* TransformComponent;

	/** Spline component to define the rail path. */
	UPROPERTY(EditDefaultsOnly, Category = "Rail Components")
		USplineComponent* RailSplineComponent;

	/** Component to define the attach point for cameras. Moves along the rail. */
	UPROPERTY(EditDefaultsOnly, Category = "Rail Components")
		USceneComponent* RailCameraMount;

#if WITH_EDITORONLY_DATA
	/** Preview meshes for visualization */
	UPROPERTY(Transient)
		USplineMeshComponent* PreviewMesh_Rail;

	UPROPERTY(Transient)
		TArray<USplineMeshComponent*> PreviewRailMeshSegments;

	UPROPERTY(Transient)
		UStaticMesh* PreviewRailStaticMesh;

	UPROPERTY(Transient)
		UStaticMeshComponent* PreviewMesh_Mount;
#endif
};
