#pragma once

class D3DConsole
{
	D3DConsole(){}
	~D3DConsole() {}

	static void* s_hWnd;
public:
	static void Initialize();
	static void MoveTo(int x, int y);
	static void SetWidth(int width);
	static void SetHeight(int height);
	static void* GetHandle();
};
