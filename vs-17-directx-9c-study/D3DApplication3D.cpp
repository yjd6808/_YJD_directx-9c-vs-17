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

	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	m_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	m_pD3DDevice->SetRenderState(D3DRS_DITHERENABLE, TRUE);
	m_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, TRUE);



	D3DMATERIAL9 mtrl;
	ZeroMemory(&mtrl, sizeof(D3DMATERIAL9));
	mtrl.Diffuse.r = 0.3f;
	mtrl.Diffuse.g = 0.3f;
	mtrl.Diffuse.b = 0.3f;
	mtrl.Diffuse.a = 1.0f;
	mtrl.Ambient.r = 1.0f;
	mtrl.Ambient.g = 1.0f;
	mtrl.Ambient.b = 1.0f;
	mtrl.Ambient.a = 1.0f;
	m_pD3DDevice->SetMaterial(&mtrl);

	ZeroMemory(&m_light0, sizeof(D3DLIGHT9));
	m_light0.Type = D3DLIGHT_DIRECTIONAL;
	m_light0.Direction = D3DXVECTOR3(0.8f, -0.8f, 0.8f);
	m_light0.Diffuse.r = 1.0f;
	m_light0.Diffuse.g = 1.0f;
	m_light0.Diffuse.b = 1.0f;

	m_light0.Specular.a = 1.0;
	m_light0.Specular.r = 1.0;
	m_light0.Specular.g = 1.0;
	m_light0.Specular.b = 1.0;

	m_pD3DDevice->SetLight(0, &m_light0);

	ZeroMemory(&m_light1, sizeof(D3DLIGHT9));
	m_light1.Type = D3DLIGHT_DIRECTIONAL;
	m_light1.Direction = D3DXVECTOR3(-0.8f, 0.8, -0.8f);
	m_light1.Diffuse.r = 1.0f;
	m_light1.Diffuse.g = 1.0f;
	m_light1.Diffuse.b = 1.0f;
	m_pD3DDevice->SetLight(1, &m_light1);

	m_camera = m_objectFactory->CreateCamera(m_hWnd);
	Add(m_camera);

	OnInit();
	for (auto iter = m_children.begin(); iter != m_children.end(); iter++)
		iter->second->OnInit();
	OnInitEnd();
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

	m_pD3DDevice->LightEnable(0, true);
	m_pD3DDevice->LightEnable(1, true);

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

void D3DApplication3D::OnInitEnd()
{
}


