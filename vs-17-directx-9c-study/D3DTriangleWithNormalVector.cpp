/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-18 오전 10:48:14
 */

#include "D3DTriangleWithNormalVector.h"

#include "D3DSphere.h"
#include "common.h"
#include "D3DMacro.h"

#include <d3dx9.h>
#include <iostream>

using namespace std;


void D3DTriangleWithNormalVector::OnInit()
{
	D3DObject::OnInit();

	if (m_length == 0.0f)
		m_length = 1.0f;

	float y = sqrt(3.0) * 2.0f / 3.0f * m_length;
	float x = m_length;
	float downy = sqrt(3.0) / 3.0f * m_length;
	

	//D3DPT_LINELIST로 구현하기위해 연결할 점끼리 붙여줌
	D3DPoint3D a = D3DPoint3D{ 0,			y,	1.0f };
	D3DPoint3D b = D3DPoint3D{ x,      -downy,	1.0f };
	D3DPoint3D c = D3DPoint3D{ -x,     -downy,	1.0f };


	D3DXVECTOR3 vecAtoB = (b - a).ToD3DXVector3(); // a -> b 벡터를 구함
	D3DXVECTOR3 vecAtoC = (c - a).ToD3DXVector3(); // a -> c 벡터를 구함

	D3DXVECTOR3 out;
	D3DXVec3Cross(&out, &vecAtoB, &vecAtoC); //a->b, a->c벡터의 외적을 구함
	D3DXVec3Normalize(&out, &out);			//단위 벡터로 만듬

	out *= m_length;

	D3DPoint3D aNormalVec = D3DPoint3D{ out.x + a.x, out.y + a.y, out.z + a.z}; //법선 벡터를 해당위치로 옮겨줌
	D3DPoint3D bNormalVec = D3DPoint3D{ out.x + b.x, out.y + b.y, out.z + b.z };
	D3DPoint3D cNormalVec = D3DPoint3D{ out.x + c.x, out.y + c.y, out.z + c.z };


	//(b-a) 외적 (c-a)
	m_vertexes.push_back({ a, D3DCOLOR_WHITE });
	m_vertexes.push_back({ b, D3DCOLOR_WHITE });

	m_vertexes.push_back({ b, D3DCOLOR_WHITE });
	m_vertexes.push_back({ c, D3DCOLOR_WHITE });

	m_vertexes.push_back({ c, D3DCOLOR_WHITE });
	m_vertexes.push_back({ a, D3DCOLOR_WHITE });

	m_vertexes.push_back({ a, D3DCOLOR_WHITE });
	m_vertexes.push_back({ aNormalVec, D3DCOLOR_WHITE });

	m_vertexes.push_back({ b, D3DCOLOR_WHITE });
	m_vertexes.push_back({ bNormalVec, D3DCOLOR_WHITE });

	m_vertexes.push_back({ c, D3DCOLOR_WHITE });
	m_vertexes.push_back({ cNormalVec, D3DCOLOR_WHITE });

	//법선 벡터
	D3DVertex3D vertexArray[12];
	for (int i = 0; i < m_vertexes.size(); i++)
		memcpy(&vertexArray[i], &m_vertexes[i], sizeof(D3DVertex3D));

	//정점 버퍼 생성
	D3DCREATE_VERTEXBUFFER(m_pD3DDevice, m_pVertextBuffer, vertexArray, sizeof(vertexArray));

	//정점 버퍼에 정점데이터 복사
	D3DLOCKCOPY(m_pVertextBuffer, vertexArray);

}

void D3DTriangleWithNormalVector::OnUpdate()
{
}




void D3DTriangleWithNormalVector::OnRender()
{
	D3DObject::OnRender();
	D3DXMATRIX scaleMat;
	D3DXMatrixScaling(&scaleMat, m_scale.x, m_scale.y, m_scale.z);

	D3DXMATRIX rotMat;
	D3DXMatrixRotationYawPitchRoll(&rotMat, m_rotation.y * 3.141592 / 180.0f, m_rotation.x * 3.141592 / 180.0f, m_rotation.z * 3.141592 / 180.0f);

	D3DXMATRIX translationMat;
	D3DXMatrixTranslation(&translationMat, m_position.x, m_position.y, m_position.z);

	D3DXMATRIX transformResult = scaleMat * rotMat* translationMat;
	m_pD3DDevice->SetTransform(D3DTS_WORLD, &transformResult);
	m_pD3DDevice->SetFVF(D3DFVF3D);
	m_pD3DDevice->SetStreamSource(0, m_pVertextBuffer, 0, sizeof(D3DVertex3D));
	m_pD3DDevice->DrawPrimitive(D3DPT_LINELIST, 0, 6);
}

void D3DTriangleWithNormalVector::OnRelease()
{
}

