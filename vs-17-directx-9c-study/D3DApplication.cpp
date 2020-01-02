#include "D3DApplication.h"
#include "D3DProperties.h"
#include "Timer.h"



LRESULT CALLBACK D3DApplication::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	} break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

D3DApplication::D3DApplication(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR    lpCmdLine,
	int       nCmdShow) :
m_hInstance(hInstance),
m_hPrevInstance(hPrevInstance),
m_lpCmdLine(lpCmdLine),
m_nCmdShow(nCmdShow)
{
	ZeroMemory(&m_winInfo, sizeof(WNDCLASSEX));

	m_winInfo.cbSize = sizeof(WNDCLASSEX);
	m_winInfo.style = CS_HREDRAW | CS_VREDRAW;
	m_winInfo.lpfnWndProc = WindowProc;
	m_winInfo.hInstance = m_hInstance;
	m_winInfo.hCursor = LoadCursor(nullptr, IDC_ARROW);
	m_winInfo.lpszClassName = "WindowClass";

	RegisterClassEx(&m_winInfo);
}

D3DApplication::~D3DApplication()
{
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
		delete iter->second;

	m_objects.clear();
}

void D3DApplication::Add(D3DObject * obj)
{
	m_objects.insert(std::make_pair(obj, obj));
}


void D3DApplication::Remove(D3DObject * obj)
{
	m_objects.erase(obj);
}



int D3DApplication::Run()
{
	if (m_isRunning == true)
		return D3DAPPLICATION_ALREADY_RUNNING;

	m_hWnd = CreateWindowEx(0,
		"WindowClass",
		"Our Direct3D Program",
		WS_OVERLAPPEDWINDOW,
		WINDOW_X, WINDOW_Y,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		nullptr,
		nullptr,
		m_hInstance,
		nullptr);

	ShowWindow(m_hWnd, m_nCmdShow);

	if (Init() == false)
		return D3DAPPLICATION_INITIALIZE_FAILED;

	m_isRunning = true;
	//윈도우상에서 일어나는 이벤트에대한 정보를 담을 구조체
	MSG msg = { 0 };

	//DirectX에선 PeekMessage를 사용해야한다.
	//PeekMessage는 앞의 4개의 인자까지는 GetMessage와 사용법이 같다.
	//5번째 인자로 PM_REMOVE 또는 PM_NOREMOVE 함수를 전달해야한다.
	while (true)
	{
		//PeekMessage 함수로 이벤트 없을 때는 false로 받아옴
		bool  bGotMsg = (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE) != 0);

		if (msg.message == WM_QUIT)
			break;

		if (bGotMsg)
		{
			//윈도우상 메세지 분석
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// 메세지가 없을 때 프레임 재생
			Update();
			Render();
		}
	}

	// clean up DirectX and COM
	Release();

	return msg.wParam;;
}


