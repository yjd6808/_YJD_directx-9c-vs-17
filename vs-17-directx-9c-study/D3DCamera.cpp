#include "common.h"
#include "D3DCamera.h"


void D3DCamera::OnInit()
{
	m_position = {-10, 0, -200.0f };		//카메라의 위치
	m_lookAt = { 0.0f, 0.0f, 0.0 };		//어디를 보는지
	m_lookUp = { 0.0f, 1.0f, 0.0f };	//위쪽이 어느방향인지

	Initialize();
	SetView();
	SetProjection();
	SetViewport();
	ShowCursor(false);
}


ostream& operator<<(ostream& os, D3DPoint3D p)
{
	cout << p.x << " / " << p.y << " / " << p.z << endl;
	return os;
}

ostream& operator<<(ostream& os, D3DXVECTOR3 p)
{
	cout << p.x << " / " << p.y << " / " << p.z << endl;
	return os;
}



void D3DCamera::OnUpdate()
{
	float moveSpeed = 0.02f;
	float rotSpeed = 0.1f;
	DWORD dwCurTime = GetTickCount();
	static DWORD dwOldTime = GetTickCount();
	m_dwElapsedTime = dwCurTime - dwOldTime;
	dwOldTime = dwCurTime;

	POINT curPt;
	GetCursorPos(&curPt);
	DWORD _CurTime = GetTickCount();
	static DWORD _OldTime = GetTickCount();



	D3DXVECTOR3 up = m_lookUp.ToD3DXVector3();
	D3DXVECTOR3 position = m_position.ToD3DXVector3();
	D3DXVECTOR3 at = m_lookAt.ToD3DXVector3();

	if (GetAsyncKeyState(0x57)) // 'W' key, front move
	{
		D3DXVECTOR3 Direction;
		D3DXVec3Normalize(&Direction, &(at - position));
		position += m_dwElapsedTime * Direction * moveSpeed;
		at += m_dwElapsedTime * Direction * moveSpeed;
	}

	if (GetAsyncKeyState(0x53)) // 'S' key, back move
	{
		D3DXVECTOR3 Direction;
		D3DXVec3Normalize(&Direction, &(at - position));
		position -= m_dwElapsedTime * Direction * moveSpeed;
		at -= m_dwElapsedTime * Direction * moveSpeed;
	}

	if (GetAsyncKeyState(0x41)) // 'A' key, left move
	{
		D3DXVECTOR3 UpNormal, ForwardNormal, Direction;
		D3DXVec3Normalize(&UpNormal, &up);
		D3DXVec3Normalize(&ForwardNormal, &(at - position));
		D3DXVec3Cross(&Direction, &ForwardNormal, &UpNormal);
		D3DXVec3Normalize(&Direction, &Direction);
		position += m_dwElapsedTime * Direction * moveSpeed;
		at += m_dwElapsedTime * Direction * moveSpeed;
	}

	if (GetAsyncKeyState(0x44)) // 'D' key, right move
	{
		D3DXVECTOR3 UpNormal, ForwardNormal, Direction;
		D3DXVec3Normalize(&UpNormal, &up);
		D3DXVec3Normalize(&ForwardNormal, &(at - position));
		D3DXVec3Cross(&Direction, &ForwardNormal, &UpNormal);
		D3DXVec3Normalize(&Direction, &Direction);
		position -= m_dwElapsedTime * Direction * moveSpeed;
		at -= m_dwElapsedTime * Direction * moveSpeed;
	}

	if (GetAsyncKeyState(0x51)) // 'Q' key, up move
	{
		position.y += m_dwElapsedTime * moveSpeed;
		at.y += m_dwElapsedTime * moveSpeed;
	}
	if (GetAsyncKeyState(0x45)) // 'E' key, down move
	{
		position.y -= m_dwElapsedTime * moveSpeed;
		at.y -= m_dwElapsedTime * moveSpeed;
	}

	if (_CurTime - _OldTime > 10)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			if (isClip)
				isClip = false;
			else
				isClip = true;
			_OldTime = _CurTime;
		}
	}
	if (isClip)
	{
		SetCursorPos(centerPt.x, centerPt.y);

		if (curPt.y < centerPt.y) // mouse up look
		{
			D3DXVECTOR3 UpNormal;
			D3DXVec3Normalize(&UpNormal, &up);
			at += m_dwElapsedTime * UpNormal * rotSpeed * 2;
		}

		if (curPt.y > centerPt.y) // mouse down look256
		{
			D3DXVECTOR3 UpNormal;
			D3DXVec3Normalize(&UpNormal, &up);
			at -= m_dwElapsedTime * UpNormal * rotSpeed * 2;
		}

		if (curPt.x < centerPt.x) // mouse left look
		{
			D3DXVECTOR3 UpNormal, ForwardNormal, Left;
			D3DXVec3Normalize(&UpNormal, &up);
			D3DXVec3Normalize(&ForwardNormal, &(at - position));
			D3DXVec3Cross(&Left, &ForwardNormal, &UpNormal);
			D3DXVec3Normalize(&Left, &Left);
			at += m_dwElapsedTime * Left * rotSpeed * 2;
		}

		if (curPt.x > centerPt.x) // mouse right look
		{
			D3DXVECTOR3 UpNormal, ForwardNormal, Right;
			D3DXVec3Normalize(&UpNormal, &up);
			D3DXVec3Normalize(&ForwardNormal, &(at - position));
			D3DXVec3Cross(&Right, &ForwardNormal, &UpNormal);
			D3DXVec3Normalize(&Right, &Right);
			at -= m_dwElapsedTime * Right * rotSpeed * 2;
		}
	}
	
	m_position.x = position.x;
	m_position.y = position.y;
	m_position.z = position.z;

	m_lookAt.x = at.x;
	m_lookAt.y = at.y;
	m_lookAt.z = at.z;

	m_lookUp.x = up.x;
	m_lookUp.y = up.y;
	m_lookUp.z = up.z;

	D3DXMatrixLookAtLH(&m_viewMat, &m_position.ToD3DXVector3(), &m_lookAt.ToD3DXVector3(), &m_lookUp.ToD3DXVector3());
	m_pD3DDevice->SetTransform(D3DTS_VIEW, &m_viewMat);
	m_pD3DDevice->SetViewport(&m_viewPort);
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

	D3DXMatrixLookAtLH(&m_viewMat, &pos, &at, &up);		//뷰스페이스 변환행렬을 얻을 수 있다.
	m_pD3DDevice->SetTransform(D3DTS_VIEW, &m_viewMat);		
}

void D3DCamera::SetViewport()
{
	RECT windowRect = { 0 };
	GetClientRect(m_hWnd, &windowRect);
	
	m_viewPort.X = 0;
	m_viewPort.Y = 0;
	m_viewPort.Width = windowRect.right - windowRect.left;
	m_viewPort.Height = windowRect.bottom - windowRect.top;
	m_viewPort.MinZ = 0.0f;
	m_viewPort.MaxZ = 1.0f;

	m_pD3DDevice->SetViewport(&m_viewPort);
}

void D3DCamera::SetProjection()
{
	D3DXMatrixPerspectiveFovLH(
		&m_projMat,			//반환 : 투영행렬
		D3DX_PI / 4,		//화면시야각 : 45도
		WINDOW_WIDTH / float(WINDOW_HEIGHT), //화면 비율
		1.0f,				
		1000.0f);												//1.0 ~ 1000.0f 사이의 물체들만 출력됨

	m_pD3DDevice->SetTransform(D3DTS_PROJECTION, &m_projMat);	//투영행렬 적용
}

void D3DCamera::Initialize()
{
	isClip = true;
	GetClientRect(m_hWnd, &rect);

	// 화면 밖으로 못 나가게 한다.
	POINT p1, p2;
	p1.x = rect.left;
	p1.y = rect.top;
	p2.x = rect.right;
	p2.y = rect.bottom;

	ClientToScreen(m_hWnd, &p1);
	ClientToScreen(m_hWnd, &p2);

	rect.left = p1.x;
	rect.top = p1.y;
	rect.right = p2.x;
	rect.bottom = p2.y;

	ClipCursor(&rect);
	centerPt.x = (p1.x + p2.x) / 2;
	centerPt.y = (p1.y + p2.y) / 2;
	// 마우스를 중앙으로 고정시킨다.
	SetCursorPos(centerPt.x, centerPt.y);
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


