#pragma once

#include <Windows.h>
#include <unordered_map>
#include "D3DObject.h"

#define D3DAPPLICATION_ALREADY_RUNNING		-1
#define D3DAPPLICATION_INITIALIZE_FAILED	-2


class D3DApplication 
{
	static LRESULT CALLBACK WindowProc(HWND hWnd,
		UINT ¸Þ½ÃÁö,
		WPARAM wParam,
		LPARAM lParam);

public:
	D3DApplication(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPWSTR    lpCmdLine,
		int       nCmdShow);
	~D3DApplication();


	void Add(D3DObject* obj);
	void Remove(D3DObject* obj);
protected:
	virtual bool Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
private:
	int Run();
protected:
	HINSTANCE	m_hInstance;
	HINSTANCE	m_hPrevInstance;
	LPWSTR		m_lpCmdLine;
	int			m_nCmdShow;

	bool		m_isRunning;
	HWND		m_hWnd;
	WNDCLASSEX	m_winInfo;
	RECT		m_rectangle;
protected:
	std::unordered_map<D3DObject*, D3DObject*> m_objects;
	friend class D3DManager;
};


