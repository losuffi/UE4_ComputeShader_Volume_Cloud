// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VCloud.h"
#include "ShaderCore.h"
#include "Interfaces/IPluginManager.h"
#define LOCTEXT_NAMESPACE "FVCloudModule"

void FVCloudModule::StartupModule()
{
	FString ShaderDirectory = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("VCloud"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/VCloud"), ShaderDirectory);
}

void FVCloudModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVCloudModule, VCloud)