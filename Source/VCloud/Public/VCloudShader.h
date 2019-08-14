#pragma once
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/RHI/Public/RHIDefinitions.h"
#include "Runtime/RHI/Public/RHIResources.h"
#include "RHI/Public/RHICommandList.h"
#include "RHI.h"
#include "GlobalShader.h"
#include "Engine/TextureRenderTarget.h"
#include "Engine/TextureRenderTarget2D.h"
#include "VCloudShader.generated.h"

USTRUCT(BlueprintType)
struct FCloudNoiseConfig
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "FCloudNoiseConfig")
		FVector2D CoverSize;
	UPROPERTY(EditAnywhere, Category = "FCloudNoiseConfig")
		FVector2D DetailSize;
	UPROPERTY(EditAnywhere, Category = "FCloudNoiseConfig")
		FVector VolumeSize;
};
UCLASS(MinimalAPI)
class UVCloudLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:
	
	UFUNCTION(BlueprintCallable, Category = "VCloud")
	static void GenerateCloudNoise(const AActor* HandleActor,const FCloudNoiseConfig& Config);
	static class FVCloudNoiseGenerator* s_Generator;
};
class FVCloudNoiseGenerator
{
public:
	void Update(ERHIFeatureLevel::Type FeatureLevel, const FCloudNoiseConfig& Config);
	void Generate();
private:
	void Generate_RenderThread();
private:
	ERHIFeatureLevel::Type m_FeatureLevel;
	FUnorderedAccessViewRHIRef uavs[3];
	FShaderResourceViewRHIRef srvs[3];
	FTextureRHIRef tex[3];
};