#include "D3DApplication3D.h"

LPDIRECT3DDEVICE9 D3DApplication3D::GetDevice()
{
	return m_pD3DDevice;
}

D3DApplication3D::~D3DApplication3D()
{	
	delete m_camera;
	delete m_objectFactory;
}

bool D3DApplication3D::Init()
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (m_pD3D == nullptr)
		return false;

	D3DPRESENT_PARAMETERS d3dParameters;
	ZeroMemory(&d3dParameters, sizeof(D3DPRESENT_PARAMETERS));
	d3dParameters.Windowed = true;
	d3dParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	
	/* z���� ���� */
	d3dParameters.EnableAutoDepthStencil = true;
	d3dParameters.AutoDepthStencilFormat = D3DFMT_D24S8;

	HRESULT createDeviceFailed = m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParameters, &m_pD3DDevice);

	if (FAILED(createDeviceFailed))
		return false;

	m_objectFactory = new D3DObjectFactory(m_pD3DDevice);

	/* z���۸� ����ϰڴ� */
	m_pD3DDevice->SetRenderState(D3DRS_ZENABLE, true);
	m_camera = m_objectFactory->CreateCamera();
	

	OnInit();
	m_camera->OnInit();
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
		iter->second->OnInit();

	return true;
}

void D3DApplication3D::Update()
{
	m_camera->OnUpdate();
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
		iter->second->OnUpdate();
	OnUpdate();
}

void D3DApplication3D::Render()
{
	if (m_pD3DDevice == nullptr)
		return;

	//z���۵� ����ش�.
	m_pD3DDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 255, 0), 1.0f, 0);

	m_pD3DDevice->BeginScene();
	OnRender();
	m_camera->OnUpdate();
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
		iter->second->OnRender();
	m_pD3DDevice->EndScene();
	m_pD3DDevice->Present(nullptr, nullptr, nullptr, nullptr);
}

void D3DApplication3D::Release()
{
	OnRelease();
	m_camera->OnRelease();
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
		iter->second->OnRelease();

	if (m_pD3DDevice != nullptr)
		m_pD3DDevice->Release();

	if (m_pD3D != nullptr)
		m_pD3D->Release();
}
