// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VCloud/Public/VCloudShader.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVCloudShader() {}
// Cross Module References
	VCLOUD_API UScriptStruct* Z_Construct_UScriptStruct_FCloudNoiseConfig();
	UPackage* Z_Construct_UPackage__Script_VCloud();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	VCLOUD_API UClass* Z_Construct_UClass_UVCloudLibrary_NoRegister();
	VCLOUD_API UClass* Z_Construct_UClass_UVCloudLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	VCLOUD_API UFunction* Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
class UScriptStruct* FCloudNoiseConfig::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VCLOUD_API uint32 Get_Z_Construct_UScriptStruct_FCloudNoiseConfig_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCloudNoiseConfig, Z_Construct_UPackage__Script_VCloud(), TEXT("CloudNoiseConfig"), sizeof(FCloudNoiseConfig), Get_Z_Construct_UScriptStruct_FCloudNoiseConfig_Hash());
	}
	return Singleton;
}
template<> VCLOUD_API UScriptStruct* StaticStruct<FCloudNoiseConfig>()
{
	return FCloudNoiseConfig::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCloudNoiseConfig(FCloudNoiseConfig::StaticStruct, TEXT("/Script/VCloud"), TEXT("CloudNoiseConfig"), false, nullptr, nullptr);
static struct FScriptStruct_VCloud_StaticRegisterNativesFCloudNoiseConfig
{
	FScriptStruct_VCloud_StaticRegisterNativesFCloudNoiseConfig()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("CloudNoiseConfig")),new UScriptStruct::TCppStructOps<FCloudNoiseConfig>);
	}
} ScriptStruct_VCloud_StaticRegisterNativesFCloudNoiseConfig;
	struct Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VolumeSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_VolumeSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DetailSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DetailSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CoverSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CoverSize;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VCloudShader.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCloudNoiseConfig>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_VolumeSize_MetaData[] = {
		{ "Category", "FCloudNoiseConfig" },
		{ "ModuleRelativePath", "Public/VCloudShader.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_VolumeSize = { "VolumeSize", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCloudNoiseConfig, VolumeSize), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_VolumeSize_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_VolumeSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_DetailSize_MetaData[] = {
		{ "Category", "FCloudNoiseConfig" },
		{ "ModuleRelativePath", "Public/VCloudShader.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_DetailSize = { "DetailSize", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCloudNoiseConfig, DetailSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_DetailSize_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_DetailSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_CoverSize_MetaData[] = {
		{ "Category", "FCloudNoiseConfig" },
		{ "ModuleRelativePath", "Public/VCloudShader.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_CoverSize = { "CoverSize", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCloudNoiseConfig, CoverSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_CoverSize_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_CoverSize_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_VolumeSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_DetailSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::NewProp_CoverSize,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VCloud,
		nullptr,
		&NewStructOps,
		"CloudNoiseConfig",
		sizeof(FCloudNoiseConfig),
		alignof(FCloudNoiseConfig),
		Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCloudNoiseConfig()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCloudNoiseConfig_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_VCloud();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CloudNoiseConfig"), sizeof(FCloudNoiseConfig), Get_Z_Construct_UScriptStruct_FCloudNoiseConfig_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCloudNoiseConfig_Hash() { return 2247373107U; }
	void UVCloudLibrary::StaticRegisterNativesUVCloudLibrary()
	{
		UClass* Class = UVCloudLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GenerateCloudNoise", &UVCloudLibrary::execGenerateCloudNoise },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics
	{
		struct VCloudLibrary_eventGenerateCloudNoise_Parms
		{
			const AActor* HandleActor;
			FCloudNoiseConfig Config;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Config;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HandleActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HandleActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::NewProp_Config_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VCloudLibrary_eventGenerateCloudNoise_Parms, Config), Z_Construct_UScriptStruct_FCloudNoiseConfig, METADATA_PARAMS(Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::NewProp_Config_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::NewProp_Config_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::NewProp_HandleActor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::NewProp_HandleActor = { "HandleActor", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VCloudLibrary_eventGenerateCloudNoise_Parms, HandleActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::NewProp_HandleActor_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::NewProp_HandleActor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::NewProp_Config,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::NewProp_HandleActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::Function_MetaDataParams[] = {
		{ "Category", "VCloud" },
		{ "ModuleRelativePath", "Public/VCloudShader.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVCloudLibrary, nullptr, "GenerateCloudNoise", sizeof(VCloudLibrary_eventGenerateCloudNoise_Parms), Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVCloudLibrary_NoRegister()
	{
		return UVCloudLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UVCloudLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVCloudLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_VCloud,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVCloudLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVCloudLibrary_GenerateCloudNoise, "GenerateCloudNoise" }, // 732800081
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVCloudLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VCloudShader.h" },
		{ "ModuleRelativePath", "Public/VCloudShader.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVCloudLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVCloudLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVCloudLibrary_Statics::ClassParams = {
		&UVCloudLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000800A0u,
		METADATA_PARAMS(Z_Construct_UClass_UVCloudLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVCloudLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVCloudLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVCloudLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVCloudLibrary, 4135175919);
	template<> VCLOUD_API UClass* StaticClass<UVCloudLibrary>()
	{
		return UVCloudLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVCloudLibrary(Z_Construct_UClass_UVCloudLibrary, &UVCloudLibrary::StaticClass, TEXT("/Script/VCloud"), TEXT("UVCloudLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVCloudLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
