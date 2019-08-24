#pragma once
#include "VCloudShader.h"
FVCloudNoiseGenerator* UVCloudLibrary::s_Generator;

REGISTER_ONE_RWTEXTURE_SHADER(FCoverNoiseShaderCS,GenerateCoverNoise,CoverMap,/Plugin/VCloud/Private/CloudMarching.usf)
REGISTER_ONE_RWTEXTURE_SHADER(FDetailNoiseShaderCS,GenerateDetailNoise,DetailMap,/Plugin/VCloud/Private/CloudMarching.usf)
REGISTER_ONE_RWTEXTURE_SHADER(FVolumeNoiseShaderCS,GenerateVolumeNoise,VolumeMap,/Plugin/VCloud/Private/CloudMarching.usf)
UVCloudLibrary::UVCloudLibrary(const FObjectInitializer& obj) :Super(obj)
{

}

void UVCloudLibrary::GenerateCloudNoise(const AActor* HandleActor,const FCloudNoiseConfig& Config)
{
	if (s_Generator == nullptr)
	{
		s_Generator = new FVCloudNoiseGenerator();
	}
	s_Generator->Update(HandleActor->GetWorld()->Scene->GetFeatureLevel(), Config);
}


void UVCloudLibrary::RenderNoiseMap()
{
	if (s_Generator)
	{
		s_Generator->Generate();
	}
}	

void FVCloudNoiseGenerator::Update(ERHIFeatureLevel::Type FeatureLevel, const FCloudNoiseConfig& Config)
{
	m_FeatureLevel = FeatureLevel;
	FRHIResourceCreateInfo info;
	tex[0] = RHICreateTexture2D(FMath::FloorToInt(Config.CoverSize.X), FMath::FloorToInt(Config.CoverSize.Y), PF_R8G8B8A8, 1, 1, TexCreate_UAV | TexCreate_ShaderResource, info);
	tex[1] = RHICreateTexture2D(FMath::FloorToInt(Config.DetailSize.X), FMath::FloorToInt(Config.DetailSize.Y), PF_R8G8B8A8, 1, 1, TexCreate_UAV | TexCreate_ShaderResource, info);
	volumeTex = RHICreateTexture3D(FMath::FloorToInt(Config.VolumeSize.X), FMath::FloorToInt(Config.VolumeSize.Y), FMath::FloorToInt(Config.VolumeSize.Z), PF_R8G8B8A8, 1, TexCreate_UAV | TexCreate_ShaderResource, info);

	uavs[0] = RHICreateUnorderedAccessView(tex[0]);
	uavs[1] = RHICreateUnorderedAccessView(tex[1]);
	uavs[2] = RHICreateUnorderedAccessView(volumeTex);

	srvs[0] = RHICreateShaderResourceView(tex[0]->GetTexture2D(), 0);
	srvs[1] = RHICreateShaderResourceView(tex[1]->GetTexture2D(), 0);
	srvs[2] = RHICreateShaderResourceView(volumeTex->GetTexture3D(), 0);
	m_Config = Config;
}

void FVCloudNoiseGenerator::Generate()
{
	ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER(
		ComputerNoiseGenerator,
		FVCloudNoiseGenerator*,
		Generator,
		this,
		{
			Generator->Generate_RenderThread();
		}
	);
}

void FVCloudNoiseGenerator::Generate_RenderThread()
{
	check(IsInRenderingThread());
	//1. 获取RHI命令队列
	FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();
	//2. 获取着色器-属于着色器部分，通过当前的SM和对应的Shader类找到着色器
	//TShaderMapRef<FCloudNoiseGeneratorCS> computeShader(GetGlobalShaderMap(m_FeatureLevel))；
	//3. 在染命令队列中设置要使用的计算着色器
	//RHICmdList.SetComputeShader(computeShader->GetComputeSHader());
	//4. 设置着色器参数
	//5. 发起Drawcall，并设置发往GPU中的指令流结构（一条指令流由一个SM执行，不同指令流之间调度执行顺序也是未知的
	//  ，同一个SM，共享内存，也存在最大wrap数目的限制，Unity中是32个wrap，即32*32）,用计算着色器的概念来描述，一个SM完成一个SV_GroupID中，所有SV_GroupThreadID的线程
	//6. 官方还有一个清理着色器参数的步骤。
	TShaderMapRef<FCoverNoiseShaderCS> CoverCs(GetGlobalShaderMap(m_FeatureLevel));
	RHICmdList.SetComputeShader(CoverCs->GetComputeShader());
	CoverCs->SetParameter(RHICmdList, uavs[0], FVector4(512,512,0,0));
	DispatchComputeShader(RHICmdList, *CoverCs, m_Config.CoverSize.X / 32, m_Config.CoverSize.Y / 32, 1);

	TShaderMapRef<FDetailNoiseShaderCS> DetailCs(GetGlobalShaderMap(m_FeatureLevel));
	RHICmdList.SetComputeShader(DetailCs->GetComputeShader());
	DetailCs->SetParameter(RHICmdList, uavs[1],FVector4(128,128,0,0));
	DispatchComputeShader(RHICmdList, *DetailCs, m_Config.DetailSize.X / 32, m_Config.DetailSize.Y / 32, 1);

	TShaderMapRef<FVolumeNoiseShaderCS> VolumeCs(GetGlobalShaderMap(m_FeatureLevel));
	RHICmdList.SetComputeShader(VolumeCs->GetComputeShader());
	VolumeCs->SetParameter(RHICmdList, uavs[2],FVector4(128,128,128,0));
	DispatchComputeShader(RHICmdList, *VolumeCs, m_Config.VolumeSize.X / 32, m_Config.VolumeSize.Y / 32, m_Config.VolumeSize.Z);
}
