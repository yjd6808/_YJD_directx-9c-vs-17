#include "D3DPlane.h"
#include <d3dx9.h>
#include <iostream>


using namespace std;

//테스트 출력
ostream& operator<<(ostream& os, D3DPoint3D& point) {
	cout << "x : " << point.x << " / ";
	cout << "y : " << point.y << " / ";
	cout << "z : " << point.z;
	return os;
}



void D3DPlane::OnInit()
{
	D3DObject::OnInit();

	if (m_width <= 0)
		m_width = 1;
	
	if (m_height <= 0)
		m_height = 1;

	if (m_squreSideLength <= 0)
		m_squreSideLength = 1.0f;

	D3DPoint3D startPos = { -0.5f * m_width * m_squreSideLength, 0.0f, 0.5f * m_height * m_squreSideLength };

	int horizontalVertexCount = m_width + 1;
	int vertialVertexCount = m_height + 1;

	for (int i = 0; i < vertialVertexCount; i++) {
		for (int j = 0; j < horizontalVertexCount; j++) {
			m_vertexes.push_back(D3DVertex3DMaterial{ D3DPoint3D(
				startPos.x + m_squreSideLength * j,
				startPos.y,
				startPos.z - m_squreSideLength * i
				),
				D3DPoint3D(
					0.0f,
					1.0f,
					0.0f
				)
				,D3DCOLOR_COLORVALUE(1, 1, 1, 1 )});

			//cout << m_vertexes[i * horizontalVertexCount + j].point << endl;
		}
		//cout << "-----------" << endl;
	}
	D3DVertex3DMaterial* vertexArray = new D3DVertex3DMaterial[horizontalVertexCount * vertialVertexCount];
	for (int i = 0; i < m_vertexes.size(); i++)
		memcpy(&vertexArray[i], &m_vertexes[i], sizeof(D3DVertex3DMaterial));

	WORD* indexArray = new WORD[m_width * m_height * 2 * 3];
	int indArrayIndex = 0;

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			indexArray[indArrayIndex++] = horizontalVertexCount * i + j;
			indexArray[indArrayIndex++] = horizontalVertexCount * i + j + 1;
			indexArray[indArrayIndex++] = horizontalVertexCount * (i + 1) + j + 1;

			indexArray[indArrayIndex++] = horizontalVertexCount * i + j;
			indexArray[indArrayIndex++] = horizontalVertexCount * (i + 1) + j + 1;
			indexArray[indArrayIndex++] = horizontalVertexCount * (i + 1) + j;
		}
	}

	//제대로 인덱스 생성됬는지 테스트
	/*int k = 0;
	for (int i = 0; i < m_width * m_height * 2 * 3; i++) {
		cout << indexArray[i] << ", ";
		k++;
		if (k >= 3) {
			k = 0;
			cout << endl;
		}
	}*/


	

	// It seems backwards, but increasing the Power value reduces the 
	// highlight's size
	m_material.Power = 40.0f;

	ULONG vertexArraySize = sizeof(D3DVertex3DMaterial) * m_vertexes.size();
	ULONG indexArraySize = sizeof(WORD) * m_width * m_height * 2 * 3;
	//정점 버퍼 생성
	D3DCREATE_VERTEXBUFFER_DYNAMIC(m_pD3DDevice, m_pVertextBuffer, vertexArray, vertexArraySize);

	//정점 버퍼에 정점데이터 복사
	D3DLOCKCOPY_DYNAMIC(m_pVertextBuffer, vertexArray, vertexArraySize);

	//인덱스 버퍼 생성
	D3DCREATE_INDEXBUFFER_DYNAMIC(m_pD3DDevice, m_pIndexBuffer, indexArray, indexArraySize);
	D3DLOCKCOPY_DYNAMIC(m_pIndexBuffer, indexArray, indexArraySize);

	delete[] vertexArray;
	delete[] indexArray;
}

void D3DPlane::OnUpdate()
{
}

void D3DPlane::OnRender()
{
	D3DObject::OnRender();

	m_pD3DDevice->SetFVF(D3DFVF3DMAT);
	m_pD3DDevice->SetStreamSource(0, m_pVertextBuffer, 0, sizeof(D3DVertex3DMaterial));
	m_pD3DDevice->SetIndices(m_pIndexBuffer);

	D3DXMATRIX scaleMat;
	D3DXMatrixScaling(&scaleMat, m_scale.x, m_scale.y, m_scale.z);

	D3DXMATRIX rotMat;
	D3DXMatrixRotationYawPitchRoll(&rotMat, m_rotation.y * 3.141592 / 180.0f, m_rotation.x * 3.141592 / 180.0f, m_rotation.z * 3.141592 / 180.0f);

	D3DXMATRIX translationMat;
	D3DXMatrixTranslation(&translationMat, m_position.x, m_position.y, m_position.z);

	D3DXMATRIX transformResult = scaleMat * rotMat* translationMat;
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &transformResult);
	m_pD3DDevice->SetMaterial(&m_material);
	m_pD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_vertexes.size(), 0, m_width * m_height * 2);

}

void D3DPlane::OnRelease()
{
	if (m_pIndexBuffer != nullptr)
		m_pIndexBuffer->Release();

	if (m_pVertextBuffer != nullptr)
		m_pVertextBuffer->Release();
}
