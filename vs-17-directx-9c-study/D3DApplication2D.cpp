#include "D3DApplication2D.h"


bool D3DApplication2D::Init()
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (m_pD3D == nullptr)
		return false;

	D3DPRESENT_PARAMETERS d3dParameters;
	ZeroMemory(&d3dParameters, sizeof(D3DPRESENT_PARAMETERS));
	d3dParameters.Windowed = true;
	d3dParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dParameters.BackBufferFormat = D3DFMT_UNKNOWN;

	HRESULT createDeviceFailed = m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParameters, &m_pD3DDevice);

	if (FAILED(createDeviceFailed))
		return false;

	OnInit();
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
		iter->second->OnInit();
	return true;
}

void D3DApplication2D::Update()
{
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
		iter->second->OnUpdate();
	OnUpdate();
}

void D3DApplication2D::Render()
{
	if (m_pD3DDevice == nullptr)
		return;

	m_pD3DDevice->Clear(0, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 255, 0), 1.0f, 0);
	m_pD3DDevice->BeginScene();
	OnRender();
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
		iter->second->OnRender();
	m_pD3DDevice->EndScene();
	m_pD3DDevice->Present(nullptr, nullptr, nullptr, nullptr);
}

void D3DApplication2D::Release()
{
	OnRelease();

	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
		iter->second->OnRelease();

	if (m_pD3DDevice != nullptr)
		m_pD3DDevice->Release();

	if (m_pD3D != nullptr)
		m_pD3D->Release();
}

