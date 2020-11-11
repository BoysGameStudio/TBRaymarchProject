// Created by Tommy Bazar. No rights reserved :)
// Special credits go to : Temaran (compute shader tutorial), TheHugeManatee (original concept, supervision)
// and Ryan Brucks (original raymarching code).

#pragma once

#include "Rendering/RaymarchTypes.h"

#include "RaymarchLight.generated.h"

class ARaymarchVolume;

UCLASS()
class RAYMARCHER_API ARaymarchLight : public AActor
{
	GENERATED_BODY()

public:
	ARaymarchLight();

	virtual void Tick(float DeltaSeconds) override;

	FDirLightParameters GetCurrentParameters() const;

	FDirLightParameters PreviousTickParameters;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float LightIntensity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

#if WITH_EDITOR
	// Override ShouldTickIfViewportsOnly to return true, so this also ticks in editor viewports.
	virtual bool ShouldTickIfViewportsOnly() const override;

#endif
};