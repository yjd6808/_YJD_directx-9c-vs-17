/*
 * @Author	: Jungdo Yun
 * @Created	: 19.12.??
 */

#include "D3DObject.h"

#include <iostream>
#include "D3DColor.h"

using namespace std;
D3DObject::D3DObject(LPDIRECT3DDEVICE9 d3dDev) :
	m_pD3DDevice(d3dDev),
	m_scale(D3DScale()),
	m_position(D3DPoint3D()),
	m_rotation(D3DRotation())
{
	m_IsSolid = false;
	m_useLight = false;
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

void D3DObject::InitSphereCollider()
{
	if (m_sphereColliderSetup == false)
		return;
		
	D3DXCreateSphere(m_pD3DDevice, m_sphereColliderLength, 15, 30, &m_sphereMesh, nullptr);
}

void D3DObject::InitHyperRectangleCollider()
{
	if (m_hyperRectangleColliderSetup == false)
		return;

	m_hyperRectangleVertexes.clear();

	float halfLength = m_hyperRectangleColliderLength / 2.0f;
	float halfDepth = m_hyperRectangleColliderDepth / 2.0f;
	float halfHeight = m_hyperRectangleColliderHeight / 2.0f;

	//앞쪽 사각형
	m_hyperRectangleVertexes.push_back({ D3DPoint3D {-halfLength, halfHeight, halfDepth}, D3DCOLOR_WHITE });
	m_hyperRectangleVertexes.push_back({ D3DPoint3D {halfLength, halfHeight, halfDepth}, D3DCOLOR_WHITE });
	m_hyperRectangleVertexes.push_back({ D3DPoint3D {halfLength, halfHeight, -halfDepth}, D3DCOLOR_WHITE });
	m_hyperRectangleVertexes.push_back({ D3DPoint3D {-halfLength, halfHeight, -halfDepth}, D3DCOLOR_WHITE });

	//뒤쪽 사각형
	m_hyperRectangleVertexes.push_back({ D3DPoint3D {-halfLength, -halfHeight, halfDepth}, D3DCOLOR_WHITE });
	m_hyperRectangleVertexes.push_back({ D3DPoint3D {halfLength, -halfHeight, halfDepth}, D3DCOLOR_WHITE });
	m_hyperRectangleVertexes.push_back({ D3DPoint3D {halfLength, -halfHeight, -halfDepth}, D3DCOLOR_WHITE });
	m_hyperRectangleVertexes.push_back({ D3DPoint3D {-halfLength, -halfHeight, -halfDepth}, D3DCOLOR_WHITE });

	D3DVertex3D vertexArray[8];
	for (int i = 0; i < m_hyperRectangleVertexes.size(); i++)
		memcpy(&vertexArray[i], &m_hyperRectangleVertexes[i], sizeof(D3DVertex3D));

	WORD indexArray[] = {
		0, 1, 2,
		0, 2, 3,
		4, 5, 6,
		4, 6, 7,
		0, 1, 5,
		0, 5, 4,
		3, 2, 6,
		3, 6, 7,
		1, 2, 6,
		1, 6, 5,
		0, 3, 7,
		0, 7, 4
	};



	//정점 버퍼 생성
	D3DCREATE_VERTEXBUFFER(m_pD3DDevice, m_phyperRectangleVertextBuffer, vertexArray);

	//정점 버퍼에 정점데이터 복사
	D3DLOCKCOPY(m_phyperRectangleVertextBuffer, vertexArray);

	//인덱스 버퍼 생성
	D3DCREATE_INDEXBUFFER(m_pD3DDevice, m_phyperRectangleIndexBuffer, indexArray);
	D3DLOCKCOPY(m_phyperRectangleIndexBuffer, indexArray);
}

void D3DObject::RenderSphereCollider()
{
	if (m_sphereColliderSetup == false)
		return;

	D3DXMATRIX scaleMat;
	D3DXMatrixScaling(&scaleMat, m_scale.x, m_scale.y, m_scale.z);

	D3DXMATRIX rotMat;
	D3DXMatrixRotationYawPitchRoll(&rotMat, m_rotation.y, m_rotation.x, m_rotation.z);

	D3DXMATRIX translationMat;
	D3DXMatrixTranslation(&translationMat, m_position.x, m_position.y, m_position.z);

	//좌표계 띵킹좀 제대로해라 z가 뒤로가면 -지 +냐 어휴..
	D3DXMATRIX transformResult = scaleMat * rotMat* translationMat;
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &transformResult);
	m_sphereMesh->DrawSubset(0);
}

void D3DObject::RenderHyperRectangleCollider()
{
	if (m_hyperRectangleColliderSetup == false)
		return;

	m_pD3DDevice->SetFVF(D3DFVF3D);
	m_pD3DDevice->SetStreamSource(0, m_phyperRectangleVertextBuffer, 0, sizeof(D3DVertex3D));
	m_pD3DDevice->SetIndices(m_phyperRectangleIndexBuffer);

	D3DXMATRIX scaleMat;
	D3DXMatrixScaling(&scaleMat, m_scale.x, m_scale.y, m_scale.z);

	D3DXMATRIX rotMat;
	D3DXMatrixRotationYawPitchRoll(&rotMat, m_rotation.y * 3.141592 / 180.0f, m_rotation.x * 3.141592 / 180.0f, m_rotation.z * 3.141592 / 180.0f);

	D3DXMATRIX translationMat;
	D3DXMatrixTranslation(&translationMat, m_position.x, m_position.y, m_position.z);

	m_hyperRectangleMin.x = m_position.x - m_hyperRectangleColliderLength / 2.0f;
	m_hyperRectangleMin.y = m_position.y - m_hyperRectangleColliderHeight / 2.0f;
	m_hyperRectangleMin.z = m_position.z - m_hyperRectangleColliderDepth / 2.0f;

	m_hyperRectangleMax.x = m_position.x + m_hyperRectangleColliderLength / 2.0f;
	m_hyperRectangleMax.y = m_position.y + m_hyperRectangleColliderHeight / 2.0f;
	m_hyperRectangleMax.z = m_position.z + m_hyperRectangleColliderDepth / 2.0f;

	D3DXMATRIX transformResult = scaleMat * rotMat* translationMat;
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &transformResult);
	m_pD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_hyperRectangleVertexes.size(), 0, 6 * 2);
}


void D3DObject::OnInit()
{
	if (m_hyperRectangleColliderSetup)
	InitSphereCollider();
	InitHyperRectangleCollider();
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
		m_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
		RenderSphereCollider();
		RenderHyperRectangleCollider();
		m_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
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

void D3DObject::SetSphereCollider(float length, bool use)
{
	m_sphereColliderLength = length;
	m_sphereColliderSetup = use;
	InitSphereCollider();
}

void D3DObject::SetHyperRectangleCollider(float length, float depth, float height, bool use)
{
	m_hyperRectangleColliderLength = length;
	m_hyperRectangleColliderDepth = depth;
	m_hyperRectangleColliderHeight = height;
	m_hyperRectangleColliderSetup = use;
	InitHyperRectangleCollider();
}

void D3DObject::SetViewCollider(bool viewCollider)
{
	m_viewCollider = viewCollider;
}



bool D3DObject::IsCollided(D3DObject * otherObject)
{
	if (m_sphereColliderSetup && otherObject->m_sphereColliderSetup) {

		if (this->DistanceFrom(otherObject) <= m_sphereColliderLength + otherObject->m_sphereColliderLength)
			return true;
	}

	if (m_hyperRectangleColliderSetup && otherObject->m_hyperRectangleColliderSetup) {
		if (this->m_hyperRectangleMin.x <= otherObject->m_hyperRectangleMax.x && this->m_hyperRectangleMax.x >= otherObject->m_hyperRectangleMin.x &&
			this->m_hyperRectangleMin.y <= otherObject->m_hyperRectangleMax.y && this->m_hyperRectangleMax.y >= otherObject->m_hyperRectangleMin.y &&
			this->m_hyperRectangleMin.z <= otherObject->m_hyperRectangleMax.z && this->m_hyperRectangleMax.z >= otherObject->m_hyperRectangleMin.z)
			return true;
		return false;
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
