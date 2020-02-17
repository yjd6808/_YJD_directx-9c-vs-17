/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-17 오전 11:55:50
 */

#include "D3DPlaneWithTexture.h"

#include <d3dx9.h>

using namespace std;

void D3DPlaneWithTexture::OnInit()
{
	float halfLength = m_length / 2.0f;

	m_vertexes.push_back({ D3DPoint3D {-halfLength, halfLength, 0.0f}, 0.0f, 5.0f });
	m_vertexes.push_back({ D3DPoint3D {halfLength, halfLength, 0.0f}, 1.0f, 0.0f });
	m_vertexes.push_back({ D3DPoint3D {-halfLength, -halfLength, 0.0f}, 0.0f, 1.0f });
	m_vertexes.push_back({ D3DPoint3D {halfLength, -halfLength, 0.0f}, 1.0f, 1.0f});

	D3DVertex3D vertexArray[4];
	for (int i = 0; i < m_vertexes.size(); i++)
		memcpy(&vertexArray[i], &m_vertexes[i], sizeof(D3DVertex3D));

	/*WORD indexArray[] = {
		0, 1, 2,
		0, 2, 3,
	};*/

	//정점 버퍼 생성
	D3DCREATE_VERTEXBUFFER(m_pD3DDevice, m_pVertextBuffer, vertexArray, sizeof(vertexArray));

	//정점 버퍼에 정점데이터 복사
	D3DLOCKCOPY(m_pVertextBuffer, vertexArray);

	/*D3DCREATE_INDEXBUFFER(m_pD3DDevice, m_pIndexBuffer, indexArray);
	D3DLOCKCOPY(m_pIndexBuffer, indexArray);*/

	if (FAILED(D3DXCreateTextureFromFile(m_pD3DDevice, "C:\\test.bmp", &m_pTexture)))
		MessageBox(nullptr, "texture load error", "", MB_OK);
}

void D3DPlaneWithTexture::OnUpdate()
{
}

void D3DPlaneWithTexture::OnRender()
{
	m_pD3DDevice->SetTexture(0, m_pTexture);
	m_pD3DDevice->SetStreamSource(0, m_pVertextBuffer, 0, sizeof(D3DVertex3DTexture));
	m_pD3DDevice->SetFVF(D3DFVF3DTEX);
	m_pD3DDevice->SetIndices(m_pIndexBuffer);

	D3DXMATRIX scaleMat;
	D3DXMatrixScaling(&scaleMat, m_scale.x, m_scale.y, m_scale.z);

	D3DXMATRIX rotMat;
	D3DXMatrixRotationYawPitchRoll(&rotMat, m_rotation.y * 3.141592 / 180.0f, m_rotation.x * 3.141592 / 180.0f, m_rotation.z * 3.141592 / 180.0f);

	D3DXMATRIX translationMat;
	D3DXMatrixTranslation(&translationMat, m_position.x, m_position.y, m_position.z);

	D3DXMATRIX transformResult = scaleMat * rotMat* translationMat;
	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &transformResult);

	m_pD3DDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
}

void D3DPlaneWithTexture::OnRelease()
{
	if (m_pIndexBuffer != nullptr)
		m_pIndexBuffer->Release();

	if (m_pVertextBuffer != nullptr)
		m_pVertextBuffer->Release();
}
