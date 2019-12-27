// vs17-directx-study.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "D3DEdu01.h"
#include "common.h"
#include "StringFormatter.h"
using namespace std;

D3DEdu01 edu01;

// WindowProc �Լ� ������ Ÿ�� 
LRESULT CALLBACK WindowProc(HWND hWnd,
	UINT �޽���,
	WPARAM wParam,
	LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.lpszClassName = "WindowClass";

	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(0,
		"WindowClass",
		"Our Direct3D Program",
		WS_OVERLAPPEDWINDOW,
		0, 0,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		nullptr,
		nullptr,
		hInstance,
		nullptr);

	ShowWindow(hWnd, nCmdShow);

	edu01.InitD3D(hWnd);

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
			edu01.Update();
			edu01.Render(); 
		}
	}

	edu01.CleanUp();

	// clean up DirectX and COM
	return msg.wParam;;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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


