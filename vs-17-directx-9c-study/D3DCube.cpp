#include "D3DCube.h"
#include "common.h"
#include "D3DMacro.h"
#include <d3dx9.h>

void D3DCube::OnInit()
{
	if (m_length == 0.0f)
		m_length = 1.0f;

	float halfLength = m_length / 2.0f;

	//앞쪽 사각형
	m_vertexes.push_back({ D3DPoint3D {-halfLength, halfLength, halfLength}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {halfLength, halfLength, halfLength}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {halfLength, halfLength, -halfLength}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {-halfLength, halfLength, -halfLength}, D3DCOLOR_WHITE });

	//뒤쪽 사각형
	m_vertexes.push_back({ D3DPoint3D {-halfLength, -halfLength, halfLength}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {halfLength, -halfLength, halfLength}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {halfLength, -halfLength, -halfLength}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {-halfLength, -halfLength, -halfLength}, D3DCOLOR_WHITE });

	D3DPoint3D vertexArray[8];
	for (int i = 0; i < m_vertexes.size(); i++)
		vertexArray[i] = vertexArray[i];

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
	m_pD3DDevice->CreateVertexBuffer(
		m_vertexes.size() * sizeof(D3DPoint3D),
		0,
		D3DFVF3D,
		D3DPOOL_DEFAULT,
		&m_pVertextBuffer,
		nullptr);

	void* vertices;
	m_pVertextBuffer->Lock(0, m_vertexes.size() * sizeof(D3DPoint3D), &vertices, 0);
	memcpy(vertices, vertexArray, m_vertexes.size() * sizeof(D3DPoint3D));
	m_pVertextBuffer->Unlock();

	//인덱스 버퍼 생성
	m_pD3DDevice->CreateIndexBuffer(
		sizeof(indexArray),
		0,
		D3DFMT_INDEX16,
		D3DPOOL_DEFAULT,
		&m_pIndexBuffer,
		nullptr);


	void* indexes;
	m_pIndexBuffer->Lock(0, sizeof(indexArray), &indexes, 0);
	memcpy(indexes, indexArray, sizeof(indexArray));
	m_pIndexBuffer->Unlock();
}

void D3DCube::OnUpdate()
{
}

void D3DCube::OnRender()
{
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld); //단위행렬로 초기화

	m_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_pD3DDevice->SetStreamSource(0, m_pVertextBuffer, 0, sizeof(D3DVertex3D));
	m_pD3DDevice->SetIndices(m_pIndexBuffer);
	m_pD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_vertexes.size(), 0, 6 * 2);
	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	m_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
}

void D3DCube::OnRelease()
{
	if (m_pIndexBuffer != nullptr)
		m_pIndexBuffer->Release();

	if (m_pVertextBuffer != nullptr)
		m_pVertextBuffer->Release();
}
