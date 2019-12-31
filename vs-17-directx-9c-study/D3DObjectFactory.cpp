#include "D3DObjectFactory.h"


D3DObjectFactory::D3DObjectFactory(LPDIRECT3DDEVICE9 d3dDev) :
	m_pD3DDevice(d3dDev)
{
}


D3DCamera* D3DObjectFactory::CreateCamera()
{
	return new D3DCamera(m_pD3DDevice);
}

D3DCube* D3DObjectFactory::CreateCube(float length)
{
	return new D3DCube(m_pD3DDevice, length);
}


