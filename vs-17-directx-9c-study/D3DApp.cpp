#include "D3DApp.h"

D3DApp::D3DApp()
{
}

D3DApp::~D3DApp()
{
}


void D3DApp::Render()
{
	if (m_pD3D == nullptr)
		return;

	//후면 버퍼를 특정 색상으로 비운다.
	m_pD3DDevice->Clear(0, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//장면 시작
	m_pD3DDevice->BeginScene();
	OnRender();
	m_pD3DDevice->EndScene();

	//인자중 3개는 스왑체인 방식 중 가장 느린 방식과 관련있다. 그래서 nullptr로 다줌
	m_pD3DDevice->Present(nullptr, nullptr, nullptr, nullptr);
	
}

void D3DApp::Update()
{
	OnUpdate();
}

void D3DApp::CleanUp()
{
	OnRelease();

	if (m_pD3D != nullptr)
		m_pD3D->Release();

	if (m_pD3DDevice != nullptr)
		m_pD3DDevice->Release();
}


HRESULT D3DApp::InitD3D(HWND hWnd)
{


	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;

	// create a device class using this information and the info from the d3dpp stuct
	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&m_pD3DDevice);

	OnInit();

	return S_OK;
}

