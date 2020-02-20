#include "D3DMeshCube.h"
#include "common.h"
#include "D3DMacro.h"
#include <d3dx9.h>

void D3DMeshCube::OnInit()
{
	D3DMeshObject::OnInit();

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


void D3DMeshCube::OnRender()
{
	D3DMeshObject::OnRender(); 

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


