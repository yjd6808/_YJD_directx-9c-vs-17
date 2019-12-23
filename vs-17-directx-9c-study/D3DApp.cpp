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

	//�ĸ� ���۸� Ư�� �������� ����.
	m_pD3DDevice->Clear(0, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	//��� ����
	if (SUCCEEDED(m_pD3DDevice->BeginScene())) 
	{
		OnRender();

		m_pD3DDevice->EndScene();
	}

	//������ 3���� ����ü�� ��� �� ���� ���� ��İ� �����ִ�. �׷��� nullptr�� ����
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
	d3dParameters.Windowed = true;						//������ ��� ��뿩��
	d3dParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;	//������ �������� ������. (����ü���� ��ȯ���)
	d3dParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dParameters.hDeviceWindow = m_hWnd;				//D3D���� ����� â

	HRESULT createDeviceResult =  m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,						//DirectX���� ����� �׷���ī�峪 
		D3DDEVTYPE_HAL,
		m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dParameters,
		&m_pD3DDevice);

	if (FAILED(createDeviceResult))
		return E_FAIL;

	OnInit();

	return S_OK; //0 ��ȯ
}

