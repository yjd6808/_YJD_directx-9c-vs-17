#include "D3DObject.h"


D3DObject::D3DObject(LPDIRECT3DDEVICE9 d3dDev) :
	m_pD3DDevice(d3dDev)
{
}

D3DObject::~D3DObject()
{
}

void D3DObject::SetPosition(const D3DPoint3D & point)
{
	m_position = point;
}

void D3DObject::SetPosition(const float x, const float y, const float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

D3DPoint3D & D3DObject::GetPosition()
{
	return m_position;
}
