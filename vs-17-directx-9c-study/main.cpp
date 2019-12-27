// vs17-directx-study.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "D3DEdu01.h"
#include "common.h"
#include "StringFormatter.h"
using namespace std;

D3DEdu01 edu01;

// WindowProc 함수 프로토 타입 
LRESULT CALLBACK WindowProc(HWND hWnd,
	UINT 메시지,
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


