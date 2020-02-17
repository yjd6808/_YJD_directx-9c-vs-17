#include "D3DApplication.h"
#include "D3DEventDispatcher.h"
#include "Timer.h"
#include "D3DManager.h"
#include "D3DMouseEvent.h"
#include "D3DKeyboardEvent.h"
#include "D3DMacro.h"

#include <iostream>

using namespace std;


LRESULT CALLBACK D3DApplication::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static D3DApplication* currentApplication = D3DManager::GetApplication();
	static D3DEventDispatcher* eventDispatcher = currentApplication->m_eventDispatcher;

	
	switch (message)
	{
	case WM_MOVE:
	case WM_SIZE:
	case WM_DESTROY:
	{
		D3DWindowEvent windowEvent;
		UpdateWindowEvent(message, wParam, &windowEvent);
		
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
		UpdateMouseEvent(message, wParam, &mouseEvent);
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

void D3DApplication::UpdateMouseEvent(UINT mouseMessage, WPARAM deltaValue, D3DMouseEvent * mouseEvent)
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
	case WM_MOUSEWHEEL:
	{
		mouseEvent->m_mouseEventType = D3DMouseEvent::MouseEventType::MOUSE_SCROLL;
		mouseEvent->m_mouseButton = D3DMouseEvent::MouseButton::BUTTON_MIDDLE;
		mouseEvent->m_scrollDeltaValue = GET_WHEEL_DELTA_WPARAM(deltaValue);
	}
	break;
	}
	eventDispatcher->DispatchEvent(mouseEvent);
	
}

void D3DApplication::UpdateKeyboardEvent(UINT keyboardMessage, WPARAM keyValue, D3DKeyboardEvent* keyboardEvent)
{
	static D3DApplication* currentApplication = D3DManager::GetApplication();
	static D3DEventDispatcher* eventDispatcher = currentApplication->m_eventDispatcher;

	switch (keyboardMessage)
	{
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
	keyboardEvent->m_isPressed = true;
	break;
	case WM_KEYUP:
	case WM_SYSKEYUP:
	keyboardEvent->m_isPressed = false;
	break;
	}
	
	auto iter = D3DKeyboardEventListener::KEY_MAP.find(keyValue);
	if (iter != D3DKeyboardEventListener::KEY_MAP.end())
		keyboardEvent->m_keyCode = iter->second;
	else
		keyboardEvent->m_keyCode = D3DKeyboardEvent::KeyCode::KEY_NONE;
	eventDispatcher->DispatchEvent(keyboardEvent);
}

void D3DApplication::UpdateWindowEvent(UINT windowMessage, WPARAM windowValue, D3DWindowEvent * windowEvent)
{
	static D3DApplication* currentApplication = D3DManager::GetApplication();
	static D3DEventDispatcher* eventDispatcher = currentApplication->m_eventDispatcher;


	RECT rect;
	GetWindowRect(currentApplication->m_hWnd, &rect);
	windowEvent->m_point.x = rect.left;
	windowEvent->m_point.y = rect.top;
	windowEvent->m_size.width = rect.right - rect.left;
	windowEvent->m_size.height = rect.bottom - rect.top;
	switch (windowMessage)
	{
	case WM_SIZE:
	{
		if (windowValue == SIZE_MINIMIZED)		windowEvent->m_windowEventType = D3DWindowEvent::WindowEventType::MINIMIZE;
		else if (windowValue == SIZE_MAXIMIZED) windowEvent->m_windowEventType = D3DWindowEvent::WindowEventType::MAXIMIZE;
		else 									windowEvent->m_windowEventType = D3DWindowEvent::WindowEventType::RESIZE;
	}
	break;
	case WM_MOVE:
	windowEvent->m_windowEventType = D3DWindowEvent::WindowEventType::MOVE;
	break;
	case WM_DESTROY:
	windowEvent->m_windowEventType = D3DWindowEvent::WindowEventType::EXIT;
	PostQuitMessage(0);
	break;
	}
	eventDispatcher->DispatchEvent(windowEvent);
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
	for (auto iter = m_children.begin(); iter != m_children.end(); iter++)
		delete iter->second;

	m_children.clear();
	delete m_eventDispatcher;
}

void D3DApplication::Add(D3DObject * obj)
{
	m_children.insert(std::make_pair(obj, obj));
}


void D3DApplication::Remove(D3DObject * obj)
{
	m_children.erase(obj);
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


