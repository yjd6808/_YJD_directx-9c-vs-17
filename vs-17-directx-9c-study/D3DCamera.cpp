#include "common.h"
#include "D3DCamera.h"


void D3DCamera::OnInit()
{
	m_position = { 0, 0, -10.0f };		//ī�޶��� ��ġ
	m_lookAt = { 0.0f, 0.0f, 0.0 };		//��� ������
	m_lookUp = { 0.0f, 1.0f, 0.0f };	//������ �����������

	SetView();
	SetProjection();
	SetViewport();
}

void D3DCamera::OnUpdate()
{
}

void D3DCamera::OnRender()
{
	SetView();
}

void D3DCamera::OnRelease()
{
}


void D3DCamera::SetView()
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 at;
	D3DXVECTOR3 up;

	pos.x = m_position.x;
	pos.y = m_position.y;
	pos.z = m_position.z;

	at.x = m_lookAt.x;
	at.y = m_lookAt.y;
	at.z = m_lookAt.z;

	up.x = m_lookUp.x;
	up.y = m_lookUp.y;
	up.z = m_lookUp.z;
	D3DXMatrixLookAtLH(&m_viewMat, &pos, &at, &up);		//�佺���̽� ��ȯ����� ���� �� �ִ�.

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
		&m_projMat,			//��ȯ : �������
		D3DX_PI / 4,		//ȭ��þ߰� : 45��
		WINDOW_WIDTH / float(WINDOW_HEIGHT), //ȭ�� ����
		1.0f,				
		1000.0f);												//1.0 ~ 1000.0f ������ ��ü�鸸 ��µ�

	m_pD3DDevice->SetTransform(D3DTS_PROJECTION, &m_projMat);	//������� ����
}

void D3DCamera::SetLookAt(D3DPoint3D lookAt)
{
	m_lookAt = lookAt;
}

void D3DCamera::SetLookAtX(float lookAt_x)
{
	m_lookAt.x = lookAt_x;
}

void D3DCamera::SetLookAtY(float lookAt_y)
{
	m_lookAt.y = lookAt_y;
}

void D3DCamera::SetLookAtZ(float lookAt_z)
{
	m_lookAt.z = lookAt_z;
}

D3DPoint3D D3DCamera::GetLookAt()
{
	return m_lookAt;
}

float D3DCamera::GetLookAtX()
{
	return m_lookAt.x;
}

float D3DCamera::GetLookAtY()
{
	return m_lookAt.y;
}

float D3DCamera::GetLookAtZ()
{
	return m_lookAt.z;
}


