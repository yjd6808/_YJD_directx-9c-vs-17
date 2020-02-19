#include "D3DObject.h"

#include <iostream>

using namespace std;
D3DObject::D3DObject(LPDIRECT3DDEVICE9 d3dDev) :
	m_pD3DDevice(d3dDev),
	m_scale(D3DScale()),
	m_position(D3DPoint3D()),
	m_rotation(D3DRotation())
{
	m_IsSolid = true;
	m_useLight = true;
	m_sphereColliderSetup = false;
	m_hyperRectangleColliderSetup = false;

	m_sphereColliderLength = 0.0f;
	m_hyperRectangleColliderDepth = 0.0f;
	m_hyperRectangleColliderHeight = 0.0f;
	m_hyperRectangleColliderLength = 0.0f;
	m_viewCollider = false;
}

D3DObject::~D3DObject()
{
	

}


void D3DObject::OnInit()
{


}

void D3DObject::OnRender()
{
	if (m_IsSolid)
		m_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	else
		m_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	if (m_useLight)
		m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	else
		m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	if (m_viewCollider) {
		
	}
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

float D3DObject::DistanceFrom(D3DObject * obj) const
{
	return sqrt(
				pow(obj->m_position.x - m_position.x, 2.0) +
				pow(obj->m_position.y - m_position.y, 2.0) +
				pow(obj->m_position.z - m_position.z, 2.0)
		   );
}

void D3DObject::SetSolid(bool solidStatus)
{
	m_IsSolid = solidStatus;
}

void D3DObject::SetLighting(bool lightingStatus)
{
	m_useLight = lightingStatus;
}

void D3DObject::SetSphereCollider(float length)
{
	m_sphereColliderLength;
}

void D3DObject::SetHyperRectangleCollider(float length, float depth, float height)
{
}

void D3DObject::SetViewCollider(bool viewCollider)
{
}

bool D3DObject::IsCollided(D3DObject * otherObject)
{
	if (m_sphereColliderSetup && otherObject->m_sphereColliderSetup) {

		if (this->DistanceFrom(otherObject) <= m_sphereColliderLength + otherObject->m_sphereColliderLength)
			return true;
	}

	if (m_hyperRectangleColliderSetup && otherObject->m_hyperRectangleColliderSetup) {

	}

	return false;
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
