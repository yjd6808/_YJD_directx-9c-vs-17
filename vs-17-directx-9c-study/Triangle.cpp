#include "Triangle.h"

void Triangle::OnInit(LPDIRECT3DDEVICE9 d3dDevice)
{
	m_pD3DDevice = d3dDevice;
	//정점 구성
	CUSTOMVERTEX vertices[] =
	{
		{ 400.0f, 62.5f, 0.5f, D3DCOLOR_XRGB(0, 0, 255), },
		{ 650.0f, 500.0f, 0.5f, D3DCOLOR_XRGB(0, 255, 0), },
		{ 150.0f, 500.0f, 0.5f, D3DCOLOR_XRGB(255, 0, 0), },
	};

	// 정점들을 버퍼에 담음
	m_pD3DDevice->CreateVertexBuffer(3 * sizeof(CUSTOMVERTEX),
		0,
		CUSTOMFVF,
		D3DPOOL_MANAGED,
		&m_Vbuffer,
		nullptr);

	VOID* pVoid;    // a void pointer

	// lock v_buffer and load the vertices into it
	m_Vbuffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, sizeof(vertices));
	m_Vbuffer->Unlock();
}

void Triangle::OnRender()
{
	// select which vertex format we are using
	m_pD3DDevice->SetFVF(CUSTOMFVF);

	// select the vertex buffer to display
	m_pD3DDevice->SetStreamSource(0, m_Vbuffer, 0, sizeof(CUSTOMVERTEX));

	// copy the vertex buffer to the back buffer
	m_pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}

void Triangle::OnRelease()
{
	if (m_Vbuffer != nullptr)
		m_Vbuffer->Release();
}
