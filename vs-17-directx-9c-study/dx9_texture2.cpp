//#include <Windows.h>
//#include <Mmsystem.h>
//#include <d3dx9.h>
//
//// SHOW_HOW_TO_UES_TCI
////#define SHOW_HOW_TO_USE_TCI
//
//LPDIRECT3D9 g_pD3D = nullptr;  // D3D 
//LPDIRECT3DDEVICE9 g_pd3dDevice = nullptr;  // �������ϴ� D3D ����̽�
//LPDIRECT3DVERTEXBUFFER9 g_pVB = nullptr;    // ���� ����
//LPDIRECT3DTEXTURE9 g_pTexture = nullptr;    // �ؽ�ó ����
//
//// ����� ���� ���� ����ü
//struct CUSTOMVERTEX {
//	D3DXVECTOR3 position;   // ���� ��ǥ
//	D3DCOLOR color;         // ���� ����
//#ifdef SHOW_HOW_TO_USE_TCI
//	FLOAT tu, tv;           // �ؽ�ó ��ǥ
//#endif
//};
//
//// ����ڰ� ������ ������ ���� ������ ��Ÿ���� FVF ��
//#ifdef SHOW_HOW_TO_USE_TCI
//#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)
//#else 
//#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)
//#endif
//
//HRESULT InitD3D(HWND hWnd);
//HRESULT InitGeometry();
//VOID Cleanup();
//VOID Render();
//VOID SetupMatrices();
//LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//
//INT WINAPI wWinMain(_In_ HINSTANCE hInst,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//	// ������ Ŭ���� ���� �� �ʱ�ȭ, ���
//	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "D3D Tutorial", NULL };
//	RegisterClassEx(&wc);
//
//	// ������ ����
//	HWND hWnd = CreateWindow("D3D Tutorial", "D3D Tutorial 01: CreateDevice", WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, GetDesktopWindow(), NULL, wc.hInstance, NULL);
//
//	// Direct3D �ʱ�ȭ
//	if (SUCCEEDED(InitD3D(hWnd))) {
//		// ���� ���� �ʱ�ȭ
//		if (SUCCEEDED(InitGeometry())) {
//			// ������ ���
//			ShowWindow(hWnd, SW_SHOWDEFAULT);
//			UpdateWindow(hWnd);
//
//			// �޼��� ����
//			MSG msg;
//			ZeroMemory(&msg, sizeof(msg));
//
//			while (msg.message != WM_QUIT) {
//				// GetMessage() �Լ��� �޸� ������� �ʴ´�.
//				if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
//					TranslateMessage(&msg);
//					DispatchMessage(&msg);
//				}
//				else {
//					// ó���� �޼����� ������ �������Ѵ�.
//					Render();
//				}
//
//			}
//		}
//	}
//
//	// ����� Ŭ������ �޸𸮸� ��ȯ�ϰ�, ��Ͽ��� �����Ѵ�.
//	UnregisterClass("D3D Tutorial", wc.hInstance);
//
//	return 0;
//}
//
//HRESULT InitD3D(HWND hWnd)
//{
//	// D3D ��ü ����
//	if (nullptr == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION))) {
//		return E_FAIL;
//	}
//
//	// D3D ����̽��� �����ϱ� ���ؼ� �ʿ��� ����ü
//	D3DPRESENT_PARAMETERS d3dpp;
//	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));  // 0���� �ʱ�ȭ���� ������ ����� ������ ���� �� �ִ�.
//
//	d3dpp.Windowed = TRUE;  // â���
//	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
//	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
//	d3dpp.EnableAutoDepthStencil = TRUE;
//	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
//
//	// D3DDEVTYPE_HAL�� �ϵ���� ������ �����ϵ��� �����Ѵ�. 
//	// �������� g_pd3dDevice�� D3D ����̽� �����͸� �����Ѵ�. 
//	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice))) {
//		return E_FAIL;
//	}
//
//	// �ﰢ���� �޸��� ǥ���ϱ� ���� �ڵ�, �ø� ����� ����.
//	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
//
//	// ���� ����
//	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
//
//	// z ���� ����� �Ҵ�.
//	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
//
//	return S_OK;
//}
//
//// ���� ���� �ʱ�ȭ, �ؽ�ó �ʱ�ȭ
//HRESULT InitGeometry()
//{
//	// sami.jpg ���Ϸκ��� �ؽ��ĸ� �����Ѵ�.
//	if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "resource\\sami.jpg", &g_pTexture)))
//		return E_FAIL;
//
//	// ���� ���� ����
//	if (FAILED(g_pd3dDevice->CreateVertexBuffer(50 * 2 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_pVB, NULL))) {
//		return E_FAIL;
//	}
//
//	CUSTOMVERTEX* pVertices;
//
//	// Lock() �Լ��� ù ��°�� �� ��° ���ڸ� 0���� �����ϸ�
//	// Vertex Buffer�� ��ü ���� ũ��� ����
//	if (FAILED(g_pVB->Lock(0, 0, (void**)&pVertices, 0))) {
//		return E_FAIL;
//	}
//
//	// ���� ���¸� ����� �˰���
//	for (DWORD i = 0; i < 50; ++i) {
//		FLOAT theta = (2 * D3DX_PI * i) / (50 - 1);
//
//		// ������ �Ʒ����� �����ϴ� ������
//		pVertices[2 * i].position = D3DXVECTOR3(sinf(theta), -1.0f, cosf(theta));
//		// ������ �Ʒ����� �����ϴ� �������� ���� ����
//		pVertices[2 * i].color = 0xffffffff;
//
//#ifdef SHOW_HOW_TO_USE_TCI
//		pVertices[2 * i].tu = ((FLOAT)i) / (50 - i);
//		pVertices[2 * i].tv = 1.0f;
//#endif
//
//		// ������ ������ �����ϴ� ������
//		pVertices[2 * i + 1].position = D3DXVECTOR3(sinf(theta), 1.0f, cosf(theta));
//		pVertices[2 * i + 1].color = 0xff808080;
//
//#ifdef SHOW_HOW_TO_USE_TCI
//		pVertices[2 * i + 1].tu = ((FLOAT)i) / (50 - i);
//		pVertices[2 * i + 1].tv = 0.0f;
//#endif
//	}
//
//	g_pVB->Unlock();
//
//	return S_OK;
//}
//
//// ��ü ���ҽ��� ��ȯ�ϴ� �Լ�
//VOID Cleanup()
//{
//	// ��ü�� ���ҽ��� ��ȯ�ϴ� ������ �߿��ϴ�.
//	// �� ������ �߸��Ǹ� ������ �߻���Ų��.
//	// ������ ����
//
//	if (g_pTexture != nullptr) {
//		g_pTexture->Release();
//	}
//
//	if (g_pVB != nullptr) {
//		g_pVB->Release();
//	}
//
//	if (g_pd3dDevice != nullptr) {
//		g_pd3dDevice->Release();
//	}
//
//	if (g_pD3D != nullptr) {
//		g_pD3D->Release();
//	}
//}
//
//// ȭ���� �׸��� �Լ�
//VOID Render()
//{
//	if (nullptr == g_pD3D || nullptr == g_pd3dDevice || nullptr == g_pVB || nullptr == g_pTexture) {
//		return;
//	}
//
//	// �ĸ� ���۸� �Ķ������� ä���. z���۸� �����.
//	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
//
//	// BeginScene() �Լ��� ����̽����� Rendering ������ �˸���.
//	if (SUCCEEDED(g_pd3dDevice->BeginScene())) {
//
//		SetupMatrices();
//
//		// MODULATE �������� ���� ���´�.
//		g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
//
//		// TEXTURE�� ���� ������ ��(DIFFUSE)�� ���´�.
//		g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
//		g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
//
//		// alpha ������ ������� �ʴ´�.
//		g_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
//
//		// ������ �ؽ�ó�� �ε����� �ο��Ѵ�.
//		g_pd3dDevice->SetTexture(0, g_pTexture);
//
//#ifdef SHOW_HOW_TO_USE_TCI
//		D3DXMATRIXA16 mat;
//
//		mat._11 = 0.25f; mat._12 = 0.00f; mat._13 = 0.00f; mat._14 = 0.00f;
//		mat._21 = 0.00f; mat._22 = 0.25f; mat._23 = 0.00f; mat._24 = 0.00f;
//		mat._31 = 0.00f; mat._32 = 0.00f; mat._33 = 0.25f; mat._34 = 0.00f;
//		mat._41 = 0.00f; mat._42 = 0.00f; mat._43 = 0.00f; mat._44 = 1.00f;
//
//		g_pd3dDevice->SetTransform(D3DTS_TEXTURE0, &mat);
//
//		g_pd3dDevice->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2);
//		g_pd3dDevice->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_CAMERASPACEPOSITION);
//#endif
//
//		// ���̾� ���������� ����.
//		//g_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
//
//		// ���� ���۸� ��� ��Ʈ������ �����Ѵ�.
//		g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
//
//		// D3D�� ���� ������ �����Ѵ�.
//		g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
//
//		// ���� ���� ��ü�� �׸���.
//		g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2 * 50 - 2);
//
//		// Rendering�� �������� �˸���.
//		g_pd3dDevice->EndScene();
//	}
//
//	// �ĸ� ���۸� ���� �׸��� ���۷� �����Ѵ�.
//	// Double Buffering(���� ����)�� ���õ� �����̴�.
//	// ���� ���۸� ����ϸ鼭 �� �Լ��� �������� ������ ����� �׷����� �ʴ´�.
//	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
//}
//
//// ����, ��, �������� ��� ����
//VOID SetupMatrices()
//{
//	// ���� ��� ����
//	D3DXMATRIXA16 matWorld;
//
//	/*UINT iTime = timeGetTime() % 1000;
//	FLOAT fAngle = iTime * ( 2.f * D3DX_PI ) / 1000.f;
//	D3DXMatrixRotationY( &matWorld, fAngle );*/
//
//	D3DXMatrixIdentity(&matWorld);
//	// �Ʒ����� �ּ��� �����ϸ� ������ x���� �������� ȸ���Ѵ�.
//	D3DXMatrixRotationX(&matWorld, timeGetTime() / 500.0f);
//	g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
//
//	// �� ��� ����
//	D3DXVECTOR3 vEyePt(0.0f, 3.0f, -5.0f);  // ī�޶��� ��ġ
//	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);    // ī�޶� �ٶ󺸴� ����
//	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);   // ī�޶��� ���⺤��
//
//	D3DXMATRIXA16 matView;
//	// ī�޶� ��ȯ ��� ���
//	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
//	// ���� ī�޶� ��ȯ ����� ����
//	g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);
//
//	// �������� ��� ����
//	D3DXMATRIXA16 matProj;
//	// ���� ��ȯ ��� ���
//	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.f);
//	// ���� ���� ��ȯ ����� ����
//	g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);
//}
//
//// ������ ���ν��� �Լ�
//LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	switch (msg) {
//	case WM_DESTROY:
//		Cleanup();
//		PostQuitMessage(0);
//		return 0;
//
//		// �޼��� ���� ����
//		/*case WM_PAINT:
//		Render();
//		ValidateRect(hWnd, NULL);
//		return 0;*/
//	}
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}
