#include "D3DConsole.h"
#include <Windows.h>

void* D3DConsole::s_hWnd = nullptr;


void D3DConsole::Initialize()
{
	if (s_hWnd == nullptr)
		s_hWnd = GetConsoleWindow();
}

void D3DConsole::MoveTo(int x, int y)
{
	HWND wnd = (HWND)s_hWnd;
	SetWindowPos(wnd, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void D3DConsole::SetWidth(int width)
{
	HWND wnd = (HWND)s_hWnd;
	RECT ConsoleRect;
	GetWindowRect(wnd, &ConsoleRect);
	MoveWindow(wnd, ConsoleRect.left, ConsoleRect.top, width, ConsoleRect.bottom - ConsoleRect.top, TRUE);
}

void D3DConsole::SetHeight(int height)
{
	HWND wnd = (HWND)s_hWnd;
	RECT ConsoleRect;
	GetWindowRect(wnd, &ConsoleRect);
	MoveWindow(wnd, ConsoleRect.left, ConsoleRect.top, ConsoleRect.right - ConsoleRect.left, height, TRUE);
}

void* D3DConsole::GetHandle()
{
	return s_hWnd;
}

