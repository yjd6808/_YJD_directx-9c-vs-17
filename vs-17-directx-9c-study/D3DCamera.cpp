#include "common.h"
#include "D3DCamera.h"


void D3DCamera::OnInit()
{
	m_position = { 0, 0, -10.0f };
	m_lookAt = { 0.0f, 0.0f, 0.0 };
	m_stdAxis = { 0.0f, 1.0f, 0.0f };

	SetView();
	SetProjection();
	SetViewport();
}

void D3DCamera::OnUpdate()
{
	if (GetAsyncKeyState('A')) {
		m_position.x -= 0.1f;
		m_lookAt.x -= 0.1f;
	}

	if (GetAsyncKeyState('D')) {
		m_position.x += 0.1f;
		m_lookAt.x += 0.1f;
	}

	if (GetAsyncKeyState('W')) {
		m_position.y += 0.1f;
		m_lookAt.y += 0.1f;
	}

	if (GetAsyncKeyState('S')) {
		m_position.y -= 0.1f;
		m_lookAt.y -= 0.1f;
	}

}

void D3DCamera::OnRender()
{
	SetView();
}

void D3DCamera::OnRelease()
{
}

void D3DCamera::SetPosition(const D3DPoint3D & point)
{

}

void D3DCamera::SetPosition(const float x, const float y, const float z)
{
}


void D3DCamera::SetView()
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 at;
	D3DXVECTOR3 axis;

	pos.x = m_position.x;
	pos.y = m_position.y;
	pos.z = m_position.z;

	at.x = m_lookAt.x;
	at.y = m_lookAt.y;
	at.z = m_lookAt.z;

	axis.x = m_stdAxis.x;
	axis.y = m_stdAxis.y;
	axis.z = m_stdAxis.z;
	D3DXMatrixLookAtLH(&m_viewMat, &pos, &at, &axis);
	m_pD3DDevice->SetTransform(D3DTS_VIEW, &m_viewMat);


}

void D3DCamera::SetViewport()
{
	RECT windowRect = { 0 };
	D3DVIEWPORT9 viewPort;

	GetClientRect(m_hWnd, &windowRect);

	viewPort.X = 0;
	viewPort.Y = 0;
	viewPort.Width = windowRect.right - windowRect.left;
	viewPort.Height = windowRect.bottom - windowRect.top;
	viewPort.MinZ = 0.0f;
	viewPort.MaxZ = 1.0f;

	m_pD3DDevice->SetViewport(&viewPort);
}

void D3DCamera::SetProjection()
{
	D3DXMatrixPerspectiveFovLH(
		&m_projMat,			//반환 : 투영행렬
		D3DX_PI / 4,		//화면시야각 : 45도
		WINDOW_WIDTH / float(WINDOW_HEIGHT), //화면 비율
		1.0f,				
		1000.0f);			//1.0 ~ 1000.0f 사이의 물체들만 출력됨

	m_pD3DDevice->SetTransform(D3DTS_PROJECTION, &m_projMat);
}