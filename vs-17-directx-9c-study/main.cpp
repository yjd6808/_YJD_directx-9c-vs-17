// vs17-directx-study.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <Windows.h>
#include <iostream>
#include <d3d9.h>

#include "D3DEdu01.h"

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
	HWND �������ڵ�;
	WNDCLASSEX �����������������Ŭ����;

	ZeroMemory(&�����������������Ŭ����, sizeof(WNDCLASSEX));

	�����������������Ŭ����.cbSize = sizeof(WNDCLASSEX);
	�����������������Ŭ����.style = CS_HREDRAW | CS_VREDRAW;
	�����������������Ŭ����.lpfnWndProc = WindowProc;
	�����������������Ŭ����.hInstance = hInstance;
	�����������������Ŭ����.hCursor = LoadCursor(NULL, IDC_ARROW);
	�����������������Ŭ����.hbrBackground = (HBRUSH)COLOR_WINDOW;
	�����������������Ŭ����.lpszClassName = "������ ������";

	RegisterClassEx(&�����������������Ŭ����);

	�������ڵ� = CreateWindowEx(
		NULL,
		"������ ������",	//â Ŭ���� �̸�
		"YJD Window",		//â ����
		WS_OVERLAPPEDWINDOW,//â ��Ÿ��
		300,				//â�� x��ġ
		300,				//â�� y��ġ
		500,				//â�� �ʺ�
		400,				//â�� ����
		NULL,				//�θ� â
		NULL,				//�޴��� ������� ����
		hInstance,			//�������α׷��� �ڵ�
		NULL				//����â�� �Բ� ���
	);

	
	
	edu01.InitD3D(�������ڵ�);

	ShowWindow(�������ڵ�, nCmdShow);

	//������󿡼� �Ͼ�� �̺�Ʈ������ ������ ���� ����ü
	MSG �޽���;

	//DirectX���� PeekMessage�� ����ؾ��Ѵ�.
	//PeekMessage�� ���� 4���� ���ڱ����� GetMessage�� ������ ����.
	//5��° ���ڷ� PM_REMOVE �Ǵ� PM_NOREMOVE �Լ��� �����ؾ��Ѵ�.
	while (true) {

		while (PeekMessage(&�޽���, �������ڵ�, 0, 0, PM_REMOVE)) {
			TranslateMessage(&�޽���);
			DispatchMessage(&�޽���);
		}

		//
		if (�޽���.message == WM_QUIT)
			break;

		edu01.OnUpdate();
		edu01.OnRender();
	}


	return �޽���.wParam;;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT �޽���, WPARAM wParam, LPARAM lParam)
{
	switch (�޽���)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	break;
	}
	return DefWindowProc(hWnd, �޽���, wParam, lParam);
}


