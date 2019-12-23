// vs17-directx-study.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <Windows.h>
#include <iostream>
#include <d3d9.h>

#include "D3DEdu01.h"

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
	HWND 윈도우핸들;
	WNDCLASSEX 윈도우의정보를담는클래스;

	ZeroMemory(&윈도우의정보를담는클래스, sizeof(WNDCLASSEX));

	윈도우의정보를담는클래스.cbSize = sizeof(WNDCLASSEX);
	윈도우의정보를담는클래스.style = CS_HREDRAW | CS_VREDRAW;
	윈도우의정보를담는클래스.lpfnWndProc = WindowProc;
	윈도우의정보를담는클래스.hInstance = hInstance;
	윈도우의정보를담는클래스.hCursor = LoadCursor(NULL, IDC_ARROW);
	윈도우의정보를담는클래스.hbrBackground = (HBRUSH)COLOR_WINDOW;
	윈도우의정보를담는클래스.lpszClassName = "정도의 윈도우";

	RegisterClassEx(&윈도우의정보를담는클래스);

	윈도우핸들 = CreateWindowEx(
		NULL,
		"정도의 윈도우",	//창 클래스 이름
		"YJD Window",		//창 제목
		WS_OVERLAPPEDWINDOW,//창 스타일
		300,				//창의 x위치
		300,				//창의 y위치
		500,				//창의 너비
		400,				//창의 높이
		NULL,				//부모 창
		NULL,				//메뉴를 사용하지 않음
		hInstance,			//응용프로그램의 핸들
		NULL				//여러창과 함께 사용
	);

	
	
	edu01.InitD3D(윈도우핸들);

	ShowWindow(윈도우핸들, nCmdShow);

	//윈도우상에서 일어나는 이벤트에대한 정보를 담을 구조체
	MSG 메시지;

	//DirectX에선 PeekMessage를 사용해야한다.
	//PeekMessage는 앞의 4개의 인자까지는 GetMessage와 사용법이 같다.
	//5번째 인자로 PM_REMOVE 또는 PM_NOREMOVE 함수를 전달해야한다.
	while (true) {

		while (PeekMessage(&메시지, 윈도우핸들, 0, 0, PM_REMOVE)) {
			TranslateMessage(&메시지);
			DispatchMessage(&메시지);
		}

		//
		if (메시지.message == WM_QUIT)
			break;

		edu01.OnUpdate();
		edu01.OnRender();
	}


	return 메시지.wParam;;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT 메시지, WPARAM wParam, LPARAM lParam)
{
	switch (메시지)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	break;
	}
	return DefWindowProc(hWnd, 메시지, wParam, lParam);
}


