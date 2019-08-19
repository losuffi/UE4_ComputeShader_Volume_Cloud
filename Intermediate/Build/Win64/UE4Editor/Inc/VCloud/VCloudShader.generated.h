// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FCloudNoiseConfig;
#ifdef VCLOUD_VCloudShader_generated_h
#error "VCloudShader.generated.h already included, missing '#pragma once' in VCloudShader.h"
#endif
#define VCLOUD_VCloudShader_generated_h

#define UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_20_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCloudNoiseConfig_Statics; \
	VCLOUD_API static class UScriptStruct* StaticStruct();


template<> VCLOUD_API UScriptStruct* StaticStruct<struct FCloudNoiseConfig>();

#define UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGenerateCloudNoise) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_HandleActor); \
		P_GET_STRUCT_REF(FCloudNoiseConfig,Z_Param_Out_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVCloudLibrary::GenerateCloudNoise(Z_Param_HandleActor,Z_Param_Out_Config); \
		P_NATIVE_END; \
	}


#define UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGenerateCloudNoise) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_HandleActor); \
		P_GET_STRUCT_REF(FCloudNoiseConfig,Z_Param_Out_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVCloudLibrary::GenerateCloudNoise(Z_Param_HandleActor,Z_Param_Out_Config); \
		P_NATIVE_END; \
	}


#define UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVCloudLibrary(); \
	friend struct Z_Construct_UClass_UVCloudLibrary_Statics; \
public: \
	DECLARE_CLASS(UVCloudLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VCloud"), VCLOUD_API) \
	DECLARE_SERIALIZER(UVCloudLibrary)


#define UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_INCLASS \
private: \
	static void StaticRegisterNativesUVCloudLibrary(); \
	friend struct Z_Construct_UClass_UVCloudLibrary_Statics; \
public: \
	DECLARE_CLASS(UVCloudLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VCloud"), VCLOUD_API) \
	DECLARE_SERIALIZER(UVCloudLibrary)


#define UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	VCLOUD_API UVCloudLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVCloudLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(VCLOUD_API, UVCloudLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVCloudLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	VCLOUD_API UVCloudLibrary(UVCloudLibrary&&); \
	VCLOUD_API UVCloudLibrary(const UVCloudLibrary&); \
public:


#define UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	VCLOUD_API UVCloudLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	VCLOUD_API UVCloudLibrary(UVCloudLibrary&&); \
	VCLOUD_API UVCloudLibrary(const UVCloudLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(VCLOUD_API, UVCloudLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVCloudLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVCloudLibrary)


#define UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_PRIVATE_PROPERTY_OFFSET
#define UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_29_PROLOG
#define UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_PRIVATE_PROPERTY_OFFSET \
	UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_RPC_WRAPPERS \
	UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_INCLASS \
	UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_PRIVATE_PROPERTY_OFFSET \
	UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_INCLASS_NO_PURE_DECLS \
	UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h_32_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class VCloudLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VCLOUD_API UClass* StaticClass<class UVCloudLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnMove_Plugins_VCloud_Source_VCloud_Public_VCloudShader_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
