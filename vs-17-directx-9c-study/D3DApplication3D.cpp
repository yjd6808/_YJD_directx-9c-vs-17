#include "D3DApplication3D.h"

LPDIRECT3DDEVICE9 D3DApplication3D::GetDevice()
{
	return m_pD3DDevice;
}

D3DApplication3D::~D3DApplication3D()
{	
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
	
	/* z버퍼 설정 */
	d3dParameters.EnableAutoDepthStencil = true;
	d3dParameters.AutoDepthStencilFormat = D3DFMT_D24S8;

	HRESULT createDeviceFailed = m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParameters, &m_pD3DDevice);

	if (FAILED(createDeviceFailed))
		return false;

	m_objectFactory = new D3DObjectFactory(m_pD3DDevice);

	/* z버퍼를 사용하겠다 */
	m_pD3DDevice->SetRenderState(D3DRS_ZENABLE, true);

	/* FVF 설정 */
	m_pD3DDevice->SetFVF(D3DFVF3D);

	/* 테두리만 보여주겠다. */
	m_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	/* 컬링을 사용하겠다. */
	m_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	

	m_camera = m_objectFactory->CreateCamera(m_hWnd);
	Add(m_camera);

	OnInit();
	for (auto iter = m_children.begin(); iter != m_children.end(); iter++)
		iter->second->OnInit();

	return true;
}

void D3DApplication3D::Update()
{
	for (auto iter = m_children.begin(); iter != m_children.end(); iter++)
		iter->second->OnUpdate();



	OnUpdate();
}

void D3DApplication3D::Render()
{
	if (m_pD3DDevice == nullptr)
		return;

	//z버퍼도 비워준다.
	m_pD3DDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	m_pD3DDevice->BeginScene();
	for (auto iter = m_children.begin(); iter != m_children.end(); iter++)
		iter->second->OnRender();
	m_pD3DDevice->EndScene();
	m_pD3DDevice->Present(nullptr, nullptr, nullptr, nullptr);
}

void D3DApplication3D::Release()
{
	for (auto iter = m_children.begin(); iter != m_children.end(); iter++)
		iter->second->OnRelease();

	if (m_pD3DDevice != nullptr)
		m_pD3DDevice->Release();

	if (m_pD3D != nullptr)
		m_pD3D->Release();
}

