#include "D3DApplication.h"
#include "D3DProperties.h"
#include "D3DEventDispatcher.h"
#include "Timer.h"
#include "D3DManager.h"
#include "D3DMouseEvent.h"
#include "D3DKeyboardEvent.h"

#include <iostream>

using namespace std;


LRESULT CALLBACK D3DApplication::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static D3DApplication* currentApplication = D3DManager::GetApplication();
	static D3DEventDispatcher* eventDispatcher = currentApplication->m_eventDispatcher;

	
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	break;
	case WM_MOUSEMOVE:
	case WM_LBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_MBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MOUSEWHEEL:
	{
		D3DMouseEvent mouseEvent;
		UpdateMouseEvent(message, &mouseEvent);
	}
	break;
	case WM_KEYDOWN:
	case WM_KEYUP:
	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
	{
		D3DKeyboardEvent keyboardEvent;
		UpdateKeyboardEvent(message, wParam, &keyboardEvent);
	}
	break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void D3DApplication::UpdateMouseEvent(UINT mouseMessage, D3DMouseEvent * mouseEvent)
{
	static D3DApplication* currentApplication = D3DManager::GetApplication();
	static D3DEventDispatcher* eventDispatcher = currentApplication->m_eventDispatcher;

	POINT mousePos;
	if (GetCursorPos(&mousePos) && ScreenToClient(currentApplication->m_hWnd, &mousePos)) 
	{
		mouseEvent->m_cursorPositionX = mousePos.x;
		mouseEvent->m_cursorPositionY = mousePos.y;
	}

	switch (mouseMessage) 
	{
	case WM_MOUSEMOVE:
	mouseEvent->m_mouseEventType = D3DMouseEvent::MouseEventType::MOUSE_MOVE;
	break;
	case WM_LBUTTONDOWN: 
	{
		mouseEvent->m_mouseEventType = D3DMouseEvent::MouseEventType::MOUSE_DOWN;
		mouseEvent->m_mouseButton = D3DMouseEvent::MouseButton::BUTTON_LEFT;
	}
	break;
	case WM_RBUTTONDOWN:
	{
		mouseEvent->m_mouseEventType = D3DMouseEvent::MouseEventType::MOUSE_DOWN;
		mouseEvent->m_mouseButton = D3DMouseEvent::MouseButton::BUTTON_RIGHT;
	}
	case WM_MBUTTONDOWN:
	{
		mouseEvent->m_mouseEventType = D3DMouseEvent::MouseEventType::MOUSE_DOWN;
		mouseEvent->m_mouseButton = D3DMouseEvent::MouseButton::BUTTON_MIDDLE;
	}
	break;
	case WM_LBUTTONUP:
	{
		mouseEvent->m_mouseEventType = D3DMouseEvent::MouseEventType::MOUSE_UP;
		mouseEvent->m_mouseButton = D3DMouseEvent::MouseButton::BUTTON_LEFT;
	}
	break;
	case WM_RBUTTONUP:
	{
		mouseEvent->m_mouseEventType = D3DMouseEvent::MouseEventType::MOUSE_UP;
		mouseEvent->m_mouseButton = D3DMouseEvent::MouseButton::BUTTON_RIGHT;
	}
	case WM_MBUTTONUP:
	{
		mouseEvent->m_mouseEventType = D3DMouseEvent::MouseEventType::MOUSE_UP;
		mouseEvent->m_mouseButton = D3DMouseEvent::MouseButton::BUTTON_MIDDLE;
	}
	break;
	}
	eventDispatcher->DispatchEvent(mouseEvent);
}

void D3DApplication::UpdateKeyboardEvent(UINT keyboardMessage, WPARAM keyValue, D3DKeyboardEvent * keyboardEvent)
{
	static D3DApplication* currentApplication = D3DManager::GetApplication();
	static D3DEventDispatcher* eventDispatcher = currentApplication->m_eventDispatcher;

}

void D3DApplication::UpdateWindowEvent(UINT message, D3DWindowEvent * windowEvent)
{
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
	m_eventDispatcher = new D3DEventDispatcher();
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
	delete m_eventDispatcher;
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


