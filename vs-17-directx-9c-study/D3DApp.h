#pragma once
#include <d3d9.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


class D3DApp
{
protected:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	HWND m_hWnd;
protected:
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnInit() = 0;
	virtual void OnRelease() = 0;

public:
	virtual void Render();
	virtual void Update();
	virtual void CleanUp();
	HRESULT InitD3D(HWND hWnd);

public:
	D3DApp();
	~D3DApp();
};