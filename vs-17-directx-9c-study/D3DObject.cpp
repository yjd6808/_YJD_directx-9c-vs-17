#include "D3DObject.h"


D3DObject::D3DObject(LPDIRECT3DDEVICE9 d3dDev) :
	m_pD3DDevice(d3dDev),
	m_scale(D3DScale()),
	m_position(D3DPoint3D()),
	m_rotation(D3DRotation())
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

void D3DObject::SetPositionX(const float x)
{
	m_position.x = x;
}

void D3DObject::SetPositionY(const float y)
{
	m_position.y = y;
}

void D3DObject::SetPositionZ(const float z)
{
	m_position.z = z;
}

D3DPoint3D D3DObject::GetPosition() const
{
	return m_position;
}

float D3DObject::GetPositionX() const
{
	return m_position.x;
}

float D3DObject::GetPositionY() const
{
	return m_position.y;
}

float D3DObject::GetPositionZ() const
{
	return m_position.z;
}

D3DRotation D3DObject::GetRotation() const
{
	return m_rotation;
}

float D3DObject::GetRotationX() const
{
	return m_rotation.x;
}

float D3DObject::GetRotationY() const
{
	return m_rotation.y;
}

float D3DObject::GetRotationZ() const
{
	return m_rotation.z;
}

D3DScale D3DObject::GetScale() const
{
	return m_scale;
}

float D3DObject::GetScaleX() const
{
	return m_scale.x;
}

float D3DObject::GetScaleY() const
{
	return m_scale.y;
}

float D3DObject::GetScaleZ() const
{
	return m_scale.z;
}

void D3DObject::SetRotation(const D3DRotation & rotation)
{
	m_rotation = rotation;
}

void D3DObject::SetRotation(const float x, const float y, const float z)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
}

void D3DObject::SetRotationX(const float x)
{
	m_rotation.x = x;
}

void D3DObject::SetRotationY(const float y)
{
	m_rotation.y = y;
}

void D3DObject::SetRotationZ(const float z)
{
	m_rotation.z = z;
}

void D3DObject::SetScale(const D3DScale & scale)
{
	m_scale = scale;
}

void D3DObject::SetScale(const float x, const float y, const float z)
{
	m_scale.x = x;
	m_scale.y = y;
	m_scale.z = z;
}

void D3DObject::SetScaleX(const float scale_x)
{
	m_scale.x = scale_x;
}

void D3DObject::SetScaleY(const float scale_y)
{
	m_scale.x = scale_y;
}

void D3DObject::SetScaleZ(const float scale_z)
{
	m_scale.x = scale_z;
}
