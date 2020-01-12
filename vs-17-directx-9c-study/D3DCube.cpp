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

	D3DVertex3D vertexArray[8];
	for (int i = 0; i < m_vertexes.size(); i++)
		memcpy(&vertexArray[i], &m_vertexes[i], sizeof(D3DVertex3D));

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
	D3DCREATE_VERTEXBUFFER(m_pD3DDevice, m_pVertextBuffer, vertexArray);

	//정점 버퍼에 정점데이터 복사
	D3DLOCKCOPY(m_pVertextBuffer, vertexArray);

	//인덱스 버퍼 생성
	D3DCREATE_INDEXBUFFER(m_pD3DDevice, m_pIndexBuffer, indexArray);
	D3DLOCKCOPY(m_pIndexBuffer, indexArray);
}

void D3DCube::OnUpdate()
{
}

void D3DCube::OnRender()
{
	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	m_pD3DDevice->SetStreamSource(0, m_pVertextBuffer, 0, sizeof(D3DVertex3D));
	m_pD3DDevice->SetIndices(m_pIndexBuffer);

	D3DXMATRIX scaleMat;
	D3DXMatrixScaling(&scaleMat, m_scale.x, m_scale.y, m_scale.z);

	D3DXMATRIX rotMat;
	D3DXMatrixRotationYawPitchRoll(&rotMat, m_rotation.y, m_rotation.x, m_rotation.z);

	D3DXMATRIX translationMat;
	D3DXMatrixTranslation(&translationMat, m_position.x, m_position.y, m_position.z);

	D3DXMATRIX transformResult = scaleMat * rotMat* translationMat;
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &transformResult);
	m_pD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_vertexes.size(), 0, 6 * 2);
	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	
}

void D3DCube::OnRelease()
{
	if (m_pIndexBuffer != nullptr)
		m_pIndexBuffer->Release();

	if (m_pVertextBuffer != nullptr)
		m_pVertextBuffer->Release();
}
