#include "D3DMeshCube.h"
#include "common.h"
#include "D3DMacro.h"
#include <d3dx9.h>

ostream& operator<<(ostream& os, D3DPoint3D p)
{
	cout << p.x << " / " << p.y << " / " << p.z << endl;
	return os;
}

ostream& operator<<(ostream& os, D3DXVECTOR3 p)
{
	cout << p.x << " / " << p.y << " / " << p.z << endl;
	return os;
}


void D3DMeshCube::OnInit()
{
	if (m_length == 0.0f)
		m_length = 1.0f;

	D3DXCreateBox(m_pD3DDevice, m_length, m_length, m_length, &m_mesh, nullptr);

	m_min.x = m_position.x - m_length / 2.0f;
	m_min.y = m_position.y - m_length / 2.0f;
	m_min.z = m_position.z - m_length / 2.0f;

	m_max.x = m_position.x + m_length / 2.0f;
	m_max.y = m_position.y + m_length / 2.0f;
	m_max.z = m_position.z + m_length / 2.0f;

}

void D3DMeshCube::OnUpdate()
{
}




void D3DMeshCube::OnRender()
{
	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	D3DXMATRIX scaleMat;
	D3DXMatrixScaling(&scaleMat, m_scale.x, m_scale.y, m_scale.z);

	D3DXMATRIX rotMat;
	D3DXMatrixRotationYawPitchRoll(&rotMat, m_rotation.y, m_rotation.x, m_rotation.z);

	D3DXMATRIX translationMat;
	D3DXMatrixTranslation(&translationMat, m_position.x, m_position.y, m_position.z);

	//좌표계 띵킹좀 제대로해라 z가 뒤로가면 -지 +냐 어휴..
	m_min.x = m_position.x - m_length / 2.0f;
	m_min.y = m_position.y - m_length / 2.0f;
	m_min.z = m_position.z - m_length / 2.0f;

	m_max.x = m_position.x + m_length / 2.0f;
	m_max.y = m_position.y + m_length / 2.0f;
	m_max.z = m_position.z + m_length / 2.0f;

	D3DXMATRIX transformResult = scaleMat * rotMat* translationMat;
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &transformResult);
	m_mesh->DrawSubset(0);
}

void D3DMeshCube::OnRelease()
{
}

bool D3DMeshCube::isCollided(D3DMeshCube * otherCube)
{
	if (this->m_min.x <= otherCube->m_max.x && this->m_max.x >= otherCube->m_min.x &&
		this->m_min.y <= otherCube->m_max.y && this->m_max.y >= otherCube->m_min.y &&
		this->m_min.z <= otherCube->m_max.z && this->m_max.z >= otherCube->m_min.z)
		return true;
	return false;
}
