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

D3DAxis* D3DObjectFactory::CreateAxis(float length)
{
	return new D3DAxis(m_pD3DDevice, length);
}

D3DPlane* D3DObjectFactory::CreatePlane(int width, int height, float squreSideLength)
{
	return new D3DPlane(m_pD3DDevice, width, height, squreSideLength);
}


