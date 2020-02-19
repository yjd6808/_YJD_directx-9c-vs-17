/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-19 오전 11:33:06
 */

#include "D3DLine.h"
#include <d3dx9.h>

void D3DLine::OnInit()
{
	D3DObject::OnInit();

	m_vertexes.push_back({ D3DPoint3D {m_start.x,	m_start.y,	m_start.z}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {m_end.x,		m_end.y,	m_end.z},	D3DCOLOR_WHITE });

	D3DVertex3D vertexArray[2];
	for (int i = 0; i < m_vertexes.size(); i++)
		memcpy(&vertexArray[i], &m_vertexes[i], sizeof(D3DVertex3D));

	//정점 버퍼 생성
	D3DCREATE_VERTEXBUFFER(m_pD3DDevice, m_pVertextBuffer, vertexArray, sizeof(vertexArray));

	//정점 버퍼에 정점데이터 복사
	D3DLOCKCOPY(m_pVertextBuffer, vertexArray);
}

void D3DLine::OnUpdate()
{
}

void D3DLine::OnRender()
{
	D3DObject::OnRender();

	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld); //단위행렬로 초기화

	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_pD3DDevice->SetFVF(D3DFVF3D);
	m_pD3DDevice->SetStreamSource(0, m_pVertextBuffer, 0, sizeof(D3DVertex3D));
	m_pD3DDevice->DrawPrimitive(D3DPT_LINELIST, 0, 1);
	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
}

void D3DLine::OnRelease()
{
	if (m_pVertextBuffer != nullptr)
		m_pVertextBuffer->Release();
}
