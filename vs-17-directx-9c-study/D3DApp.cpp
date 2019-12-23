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
	m_pD3DDevice->Clear(0, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	//장면 시작
	if (SUCCEEDED(m_pD3DDevice->BeginScene())) 
	{
		OnRender();

		m_pD3DDevice->EndScene();
	}

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
	m_hWnd = hWnd;
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (m_pD3D == nullptr)
		return E_FAIL;

	D3DPRESENT_PARAMETERS d3dParameters;
	ZeroMemory(&d3dParameters, sizeof(D3DPRESENT_PARAMETERS));
	d3dParameters.Windowed = true;						//윈도우 모드 사용여부
	d3dParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;	//오래된 프레임을 버린다. (스왑체인의 교환방식)
	d3dParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dParameters.hDeviceWindow = m_hWnd;				//D3D에서 사용할 창

	HRESULT createDeviceResult =  m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,						//DirectX에서 사용할 그래픽카드나 
		D3DDEVTYPE_HAL,
		m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dParameters,
		&m_pD3DDevice);

	if (FAILED(createDeviceResult))
		return E_FAIL;

	OnInit();

	return S_OK; //0 반환
}

