//#include <Windows.h>
//#include <Mmsystem.h>
//#include <d3dx9.h>
//
//// SHOW_HOW_TO_UES_TCI
////#define SHOW_HOW_TO_USE_TCI
//
//LPDIRECT3D9 g_pD3D = nullptr;  // D3D 
//LPDIRECT3DDEVICE9 g_pd3dDevice = nullptr;  // 렌더링하는 D3D 디바이스
//LPDIRECT3DVERTEXBUFFER9 g_pVB = nullptr;    // 정점 버퍼
//LPDIRECT3DTEXTURE9 g_pTexture = nullptr;    // 텍스처 정보
//
//// 사용자 정의 정점 구조체
//struct CUSTOMVERTEX {
//	D3DXVECTOR3 position;   // 정점 좌표
//	D3DCOLOR color;         // 정점 색깔
//#ifdef SHOW_HOW_TO_USE_TCI
//	FLOAT tu, tv;           // 텍스처 좌표
//#endif
//};
//
//// 사용자가 설정한 정점에 대한 정보를 나타내는 FVF 값
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
//	// 윈도우 클래스 선언 및 초기화, 등록
//	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "D3D Tutorial", NULL };
//	RegisterClassEx(&wc);
//
//	// 윈도우 생성
//	HWND hWnd = CreateWindow("D3D Tutorial", "D3D Tutorial 01: CreateDevice", WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, GetDesktopWindow(), NULL, wc.hInstance, NULL);
//
//	// Direct3D 초기화
//	if (SUCCEEDED(InitD3D(hWnd))) {
//		// 정점 버퍼 초기화
//		if (SUCCEEDED(InitGeometry())) {
//			// 윈도우 출력
//			ShowWindow(hWnd, SW_SHOWDEFAULT);
//			UpdateWindow(hWnd);
//
//			// 메세지 루프
//			MSG msg;
//			ZeroMemory(&msg, sizeof(msg));
//
//			while (msg.message != WM_QUIT) {
//				// GetMessage() 함수의 달리 대기하지 않는다.
//				if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
//					TranslateMessage(&msg);
//					DispatchMessage(&msg);
//				}
//				else {
//					// 처리할 메세지가 없으면 렌더링한다.
//					Render();
//				}
//
//			}
//		}
//	}
//
//	// 등록한 클래스의 메모리를 반환하고, 등록에서 제외한다.
//	UnregisterClass("D3D Tutorial", wc.hInstance);
//
//	return 0;
//}
//
//HRESULT InitD3D(HWND hWnd)
//{
//	// D3D 객체 생성
//	if (nullptr == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION))) {
//		return E_FAIL;
//	}
//
//	// D3D 디바이스를 생성하기 위해서 필요한 구조체
//	D3DPRESENT_PARAMETERS d3dpp;
//	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));  // 0으로 초기화하지 않으면 결과가 나오지 않을 수 있다.
//
//	d3dpp.Windowed = TRUE;  // 창모드
//	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
//	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
//	d3dpp.EnableAutoDepthStencil = TRUE;
//	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
//
//	// D3DDEVTYPE_HAL은 하드웨어 가속을 지원하도록 설정한다. 
//	// 전역변수 g_pd3dDevice에 D3D 디바이스 포인터를 저장한다. 
//	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice))) {
//		return E_FAIL;
//	}
//
//	// 삼각형의 뒷면을 표시하기 위한 코드, 컬링 기능을 끈다.
//	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
//
//	// 조명 끄기
//	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
//
//	// z 버퍼 기능을 켠다.
//	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
//
//	return S_OK;
//}
//
//// 정점 버퍼 초기화, 텍스처 초기화
//HRESULT InitGeometry()
//{
//	// sami.jpg 파일로부터 텍스쳐를 생성한다.
//	if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "resource\\sami.jpg", &g_pTexture)))
//		return E_FAIL;
//
//	// 정점 버퍼 생성
//	if (FAILED(g_pd3dDevice->CreateVertexBuffer(50 * 2 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_pVB, NULL))) {
//		return E_FAIL;
//	}
//
//	CUSTOMVERTEX* pVertices;
//
//	// Lock() 함수의 첫 번째와 두 번째 인자를 0으로 전달하면
//	// Vertex Buffer의 전체 버퍼 크기로 설정
//	if (FAILED(g_pVB->Lock(0, 0, (void**)&pVertices, 0))) {
//		return E_FAIL;
//	}
//
//	// 원통 형태를 만드는 알고리즘
//	for (DWORD i = 0; i < 50; ++i) {
//		FLOAT theta = (2 * D3DX_PI * i) / (50 - 1);
//
//		// 원통의 아랫면을 구성하는 정점들
//		pVertices[2 * i].position = D3DXVECTOR3(sinf(theta), -1.0f, cosf(theta));
//		// 원통의 아랫면을 구성하는 정점들의 색깔 설정
//		pVertices[2 * i].color = 0xffffffff;
//
//#ifdef SHOW_HOW_TO_USE_TCI
//		pVertices[2 * i].tu = ((FLOAT)i) / (50 - i);
//		pVertices[2 * i].tv = 1.0f;
//#endif
//
//		// 원통의 윗면을 구성하는 정점들
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
//// 객체 리소스를 반환하는 함수
//VOID Cleanup()
//{
//	// 객체의 리소스를 반환하는 순서가 중요하다.
//	// 이 순서가 잘못되면 에러를 발생시킨다.
//	// 생성의 역순
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
//// 화면을 그리는 함수
//VOID Render()
//{
//	if (nullptr == g_pD3D || nullptr == g_pd3dDevice || nullptr == g_pVB || nullptr == g_pTexture) {
//		return;
//	}
//
//	// 후면 버퍼를 파란색으로 채운다. z버퍼를 지운다.
//	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
//
//	// BeginScene() 함수로 디바이스에게 Rendering 시작을 알린다.
//	if (SUCCEEDED(g_pd3dDevice->BeginScene())) {
//
//		SetupMatrices();
//
//		// MODULATE 연산으로 색을 섞는다.
//		g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
//
//		// TEXTURE의 색과 정점의 색(DIFFUSE)을 섞는다.
//		g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
//		g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
//
//		// alpha 연산을 사용하지 않는다.
//		g_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
//
//		// 생성한 텍스처에 인덱스를 부여한다.
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
//		// 와이어 프레임으로 본다.
//		//g_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
//
//		// 정점 버퍼를 출력 스트림으로 설정한다.
//		g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
//
//		// D3D에 정점 정보를 제공한다.
//		g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
//
//		// 실제 기하 물체를 그린다.
//		g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2 * 50 - 2);
//
//		// Rendering이 끝났음을 알린다.
//		g_pd3dDevice->EndScene();
//	}
//
//	// 후면 버퍼를 현재 그리는 버퍼로 설정한다.
//	// Double Buffering(이중 버퍼)와 관련된 내용이다.
//	// 이중 버퍼를 사용하면서 이 함수를 실행하지 않으면 제대로 그려지지 않는다.
//	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
//}
//
//// 월드, 뷰, 프로젝션 행렬 설정
//VOID SetupMatrices()
//{
//	// 월드 행렬 설정
//	D3DXMATRIXA16 matWorld;
//
//	/*UINT iTime = timeGetTime() % 1000;
//	FLOAT fAngle = iTime * ( 2.f * D3DX_PI ) / 1000.f;
//	D3DXMatrixRotationY( &matWorld, fAngle );*/
//
//	D3DXMatrixIdentity(&matWorld);
//	// 아래줄의 주석을 해제하면 원통이 x축을 기준으로 회전한다.
//	D3DXMatrixRotationX(&matWorld, timeGetTime() / 500.0f);
//	g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
//
//	// 뷰 행렬 설정
//	D3DXVECTOR3 vEyePt(0.0f, 3.0f, -5.0f);  // 카메라의 위치
//	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);    // 카메라가 바라보는 지점
//	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);   // 카메라의 상향벡터
//
//	D3DXMATRIXA16 matView;
//	// 카메라 변환 행렬 계산
//	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
//	// 계산된 카메라 변환 행렬을 적용
//	g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);
//
//	// 프로젝션 행렬 설정
//	D3DXMATRIXA16 matProj;
//	// 투영 변환 행렬 계산
//	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.f);
//	// 계산된 투영 변환 행렬을 적용
//	g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);
//}
//
//// 윈도우 프로시저 함수
//LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	switch (msg) {
//	case WM_DESTROY:
//		Cleanup();
//		PostQuitMessage(0);
//		return 0;
//
//		// 메세지 루프 변경
//		/*case WM_PAINT:
//		Render();
//		ValidateRect(hWnd, NULL);
//		return 0;*/
//	}
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}
