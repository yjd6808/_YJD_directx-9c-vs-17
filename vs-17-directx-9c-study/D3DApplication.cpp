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
	//������󿡼� �Ͼ�� �̺�Ʈ������ ������ ���� ����ü
	MSG msg = { 0 };

	//DirectX���� PeekMessage�� ����ؾ��Ѵ�.
	//PeekMessage�� ���� 4���� ���ڱ����� GetMessage�� ������ ����.
	//5��° ���ڷ� PM_REMOVE �Ǵ� PM_NOREMOVE �Լ��� �����ؾ��Ѵ�.
	while (true)
	{
		//PeekMessage �Լ��� �̺�Ʈ ���� ���� false�� �޾ƿ�
		bool  bGotMsg = (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE) != 0);

		if (msg.message == WM_QUIT)
			break;

		if (bGotMsg)
		{
			//������� �޼��� �м�
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// �޼����� ���� �� ������ ���
			Update();
			Render();
		}
	}

	// clean up DirectX and COM
	Release();

	return msg.wParam;;
}


