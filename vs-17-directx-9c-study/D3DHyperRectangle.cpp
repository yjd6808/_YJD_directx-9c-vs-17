#include "D3DHyperRectangle.h"
#include "common.h"
#include "D3DMacro.h"
#include <d3dx9.h>

void D3DHyperRectangle::OnInit()
{
	D3DObject::OnInit();

	if (m_length == 0.0f)
		m_length = 1.0f;

	float halfLength = m_length / 2.0f;
	float halfDepth = m_depth / 2.0f;
	float halfHeight = m_height / 2.0f;

	//앞쪽 사각형
	m_vertexes.push_back({ D3DPoint3D {-halfLength, halfHeight, halfDepth}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {halfLength, halfHeight, halfDepth}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {halfLength, halfHeight, -halfDepth}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {-halfLength, halfHeight, -halfDepth}, D3DCOLOR_WHITE });

	//뒤쪽 사각형
	m_vertexes.push_back({ D3DPoint3D {-halfLength, -halfHeight, halfDepth}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {halfLength, -halfHeight, halfDepth}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {halfLength, -halfHeight, -halfDepth}, D3DCOLOR_WHITE });
	m_vertexes.push_back({ D3DPoint3D {-halfLength, -halfHeight, -halfDepth}, D3DCOLOR_WHITE });

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

void D3DHyperRectangle::OnUpdate()
{
}



void D3DHyperRectangle::OnRender()
{
	D3DObject::OnRender();

	m_pD3DDevice->SetFVF(D3DFVF3D);
	m_pD3DDevice->SetStreamSource(0, m_pVertextBuffer, 0, sizeof(D3DVertex3D));
	m_pD3DDevice->SetIndices(m_pIndexBuffer);

	D3DXMATRIX scaleMat;
	D3DXMatrixScaling(&scaleMat, m_scale.x, m_scale.y, m_scale.z);

	D3DXMATRIX rotMat;
	D3DXMatrixRotationYawPitchRoll(&rotMat, m_rotation.y * 3.141592 / 180.0f, m_rotation.x * 3.141592 / 180.0f, m_rotation.z * 3.141592 / 180.0f);

	D3DXMATRIX translationMat;
	D3DXMatrixTranslation(&translationMat, m_position.x, m_position.y, m_position.z);

	m_min.x = m_position.x - m_length / 2.0f;
	m_min.y = m_position.y - m_height / 2.0f;
	m_min.z = m_position.z - m_depth / 2.0f;

	m_max.x = m_position.x + m_length / 2.0f;
	m_max.y = m_position.y + m_height / 2.0f;
	m_max.z = m_position.z + m_depth / 2.0f;

	D3DXMATRIX transformResult = scaleMat * rotMat* translationMat;
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &transformResult);
	m_pD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_vertexes.size(), 0, 6 * 2);
}

void D3DHyperRectangle::OnRelease()
{
	if (m_pIndexBuffer != nullptr)
		m_pIndexBuffer->Release();

	if (m_pVertextBuffer != nullptr)
		m_pVertextBuffer->Release();
}
