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
#include "ShaderParameterUtils.h"
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
	UFUNCTION(BlueprintCallable, Category = "VCloud")
	static void RenderNoiseMap();
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
	FCloudNoiseConfig m_Config;
	ERHIFeatureLevel::Type m_FeatureLevel;
	FUnorderedAccessViewRHIRef uavs[3];
	FShaderResourceViewRHIRef srvs[3];
	FTexture2DRHIRef tex[2];
	FTexture3DRHIRef volumeTex;
};




#define REGISTER_ONE_RWTEXTURE_SHADER(ShaderClassName,KernelName,RWTextureName,Path) \
class ShaderClassName :public FGlobalShader \
{ \
	DECLARE_SHADER_TYPE(ShaderClassName, Global); \
public: \
	ShaderClassName(){} \
	ShaderClassName(const ShaderMetaType::CompiledShaderInitializerType initializer) : FGlobalShader(initializer) \
	{\
		RWTextureName.Bind(initializer.ParameterMap, TEXT(#RWTextureName));\
		SizeParameter.Bind(initializer.ParameterMap, TEXT("RWSize"));\
	}\
	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment) \
	{\
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment); \
	}\
	virtual bool Serialize(FArchive& Ar) override \
	{\
		bool ShaderHasOutputParameters = FGlobalShader::Serialize(Ar);\
		Ar << RWTextureName;\
		return ShaderHasOutputParameters;\
	}\
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)\
	{\
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);\
	}\
	void SetParameter(FRHICommandList& RHICmdList, FUnorderedAccessViewRHIRef uav, FVector4 size)\
	{\
		FComputeShaderRHIRef ShaderRHI = GetComputeShader();\
		SetUAVParameter(RHICmdList, ShaderRHI, RWTextureName, uav);\
		SetShaderValue(RHICmdList, ShaderRHI, SizeParameter, size);\
	}\
private: \
	FShaderResourceParameter RWTextureName;\
	FShaderParameter SizeParameter;\
};\
IMPLEMENT_SHADER_TYPE( ,ShaderClassName,TEXT(#Path),TEXT(#KernelName),SF_Compute)

