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
	//1. ��ȡRHI�������
	FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();
	//2. ��ȡ��ɫ��-������ɫ�����֣�ͨ����ǰ��SM�Ͷ�Ӧ��Shader���ҵ���ɫ��
	//TShaderMapRef<FCloudNoiseGeneratorCS> computeShader(GetGlobalShaderMap(m_FeatureLevel))��
	//3. ��Ⱦ�������������Ҫʹ�õļ�����ɫ��
	//RHICmdList.SetComputeShader(computeShader->GetComputeSHader());
	//4. ������ɫ������
	//5. ����Drawcall�������÷���GPU�е�ָ�����ṹ��һ��ָ������һ��SMִ�У���ָͬ����֮�����ִ��˳��Ҳ��δ֪��
	//  ��ͬһ��SM�������ڴ棬Ҳ�������wrap��Ŀ�����ƣ�Unity����32��wrap����32*32��,�ü�����ɫ���ĸ�����������һ��SM���һ��SV_GroupID�У�����SV_GroupThreadID���߳�
	//6. �ٷ�����һ��������ɫ�������Ĳ��衣
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
