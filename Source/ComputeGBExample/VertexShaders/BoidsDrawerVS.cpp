#include "BoidsDrawerVS.h"
#include "CommonRenderResources.h"

void FSimpleScreenVertexBuffer::InitRHI(FRHICommandListBase& RHICmdList)
{
	TResourceArray<FFilterVertex, VERTEXBUFFER_ALIGNMENT> Vertices;
	Vertices.SetNumUninitialized(6);

	Vertices[0].Position = FVector4f(-1, 1, 0, 1);
	Vertices[0].UV = FVector2f(0, 0);

	Vertices[1].Position = FVector4f(1, 1, 0, 1);
	Vertices[1].UV = FVector2f(1, 0);

	Vertices[2].Position = FVector4f(-1, -1, 0, 1);
	Vertices[2].UV = FVector2f(0, 1);

	Vertices[3].Position = FVector4f(1, -1, 0, 1);
	Vertices[3].UV = FVector2f(1, 1);

	// Create vertex buffer. Fill buffer with initial data upon creation
	FRHIResourceCreateInfo CreateInfo(TEXT("ShaderDemoSquare"), &Vertices);
	VertexBufferRHI = RHICmdList.CreateVertexBuffer(Vertices.GetResourceDataSize(), BUF_Static, CreateInfo);
}

bool FSimplePassThroughVS::ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
{
	// This example shader uses wave operations, so it requires SM6.
	return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM6);
}