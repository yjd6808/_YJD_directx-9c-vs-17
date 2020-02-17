/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-17 오후 6:35:22
 */

#include "D3DSphere.h"
#include "common.h"
#include "D3DMacro.h"
#include <d3dx9.h>


void D3DSphere::OnInit()
{
	if (m_radious == 0.0f)
		m_radious = 1.0f;

	D3DXCreateSphere(m_pD3DDevice, m_radious, 10, 20, &m_mesh, nullptr);


}

void D3DSphere::OnUpdate()
{
}




void D3DSphere::OnRender()
{
	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	D3DXMATRIX scaleMat;
	D3DXMatrixScaling(&scaleMat, m_scale.x, m_scale.y, m_scale.z);

	D3DXMATRIX rotMat;
	D3DXMatrixRotationYawPitchRoll(&rotMat, m_rotation.y, m_rotation.x, m_rotation.z);

	D3DXMATRIX translationMat;
	D3DXMatrixTranslation(&translationMat, m_position.x, m_position.y, m_position.z);

	//좌표계 띵킹좀 제대로해라 z가 뒤로가면 -지 +냐 어휴..
	D3DXMATRIX transformResult = scaleMat * rotMat* translationMat;
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &transformResult);
	m_mesh->DrawSubset(0);
}

void D3DSphere::OnRelease()
{
}

bool D3DSphere::isCollided(D3DSphere * otherSphere)
{
	if (this->DistanceFrom(otherSphere) <= m_radious + otherSphere->m_radious)
		return true;
	return false;
}
