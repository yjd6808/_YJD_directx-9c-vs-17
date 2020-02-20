/*
 * @Author	: Jungdo Yun
 * @Created	: 19.12.??
 */

#include "D3DObjectFactory.h"


D3DObjectFactory::D3DObjectFactory(LPDIRECT3DDEVICE9 d3dDev) :
	m_pD3DDevice(d3dDev)
{
}

D3DCamera* D3DObjectFactory::CreateCamera(HWND hwnd)
{
	return new D3DCamera(m_pD3DDevice, hwnd);
}

D3DCube* D3DObjectFactory::CreateCube(float length)
{
	return new D3DCube(m_pD3DDevice, length);
}

D3DMeshCube * D3DObjectFactory::CreateMeshCube(float length)
{
	return new D3DMeshCube(m_pD3DDevice, length);
}

D3DAxis* D3DObjectFactory::CreateAxis(float length)
{
	return new D3DAxis(m_pD3DDevice, length);
}

D3DPlane* D3DObjectFactory::CreatePlane(int width, int height, float squreSideLength)
{
	return new D3DPlane(m_pD3DDevice, width, height, squreSideLength);
}

D3DText * D3DObjectFactory::CreateText(std::string text)
{
	return new D3DText(m_pD3DDevice, text);
}

D3DMeshSphere * D3DObjectFactory::CreateSphere(float radious)
{
	return new D3DMeshSphere(m_pD3DDevice, radious);
}

D3DPlaneWithTexture * D3DObjectFactory::CreatePlaneWithTexture(int length, std::string TextureFileName)
{
	return new D3DPlaneWithTexture(m_pD3DDevice, length, TextureFileName);
}

D3DTriangleWithNormalVector * D3DObjectFactory::CreateTriangleWithNormalVector(int length)
{
	return new D3DTriangleWithNormalVector(m_pD3DDevice, length);
}

D3DHyperRectangle * D3DObjectFactory::CreateHypderRectangle(float length, float depth, float height)
{
	return new D3DHyperRectangle(m_pD3DDevice, length, depth, height); return nullptr;
}

D3DLine * D3DObjectFactory::CreateLine(D3DPoint3D start, D3DPoint3D end)
{
	return new D3DLine(m_pD3DDevice, start, end);
}


