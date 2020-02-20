#include "D3DAxis.h"
#include <d3dx9.h>

void D3DAxis::OnInit()
{
	D3DObject::OnInit();

	if (m_length == 0.0f)
		m_length = 1.0f;

	float halfLength = m_length / 2.0f;

	//축
	m_vertexes.push_back({ D3DPoint3D {-halfLength, 0.0f, 0.0f}, D3DCOLOR_RED });
	m_vertexes.push_back({ D3DPoint3D {halfLength, 0.0f, 0.0f}, D3DCOLOR_RED });

	//y축
	m_vertexes.push_back({ D3DPoint3D {0.0f, -halfLength, 0.0f}, D3DCOLOR_GREEN });
	m_vertexes.push_back({ D3DPoint3D {0.0f, halfLength, 0.0f}, D3DCOLOR_GREEN });

	//z축
	m_vertexes.push_back({ D3DPoint3D { 0.0f, 0.0f, -halfLength}, D3DCOLOR_CYAN });
	m_vertexes.push_back({ D3DPoint3D { 0.0f, 0.0f, halfLength}, D3DCOLOR_CYAN });

	D3DVertex3D vertexArray[6];
	for (int i = 0; i < m_vertexes.size(); i++)
		memcpy(&vertexArray[i], &m_vertexes[i], sizeof(D3DVertex3D));

	//정점 버퍼 생성
	D3DCREATE_VERTEXBUFFER(m_pD3DDevice, m_pVertextBuffer, vertexArray, sizeof(vertexArray));

	//정점 버퍼에 정점데이터 복사
	D3DLOCKCOPY(m_pVertextBuffer, vertexArray);
}

void D3DAxis::OnRender()
{
	D3DObject::OnRender();

	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld); //단위행렬로 초기화

	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_pD3DDevice->SetFVF(D3DFVF3D);
	m_pD3DDevice->SetStreamSource(0, m_pVertextBuffer, 0, sizeof(D3DVertex3D));
	m_pD3DDevice->DrawPrimitive(D3DPT_LINELIST, 0, 3);
	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
}

void D3DAxis::OnRelease()
{
	if (m_pVertextBuffer != nullptr)
		m_pVertextBuffer->Release();
}
