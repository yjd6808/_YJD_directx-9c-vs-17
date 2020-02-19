#pragma once

#include "D3DObject.h"
#include "D3DEventDispatcher.h"
#include "D3DMouseEventListener.h"
#include "D3DWindowEventListener.h"
#include "D3DKeyboardEventListener.h"

#include <Windows.h>
#include <unordered_map>

#define D3DAPPLICATION_ALREADY_RUNNING		-1
#define D3DAPPLICATION_INITIALIZE_FAILED	-2


class D3DApplication 
{
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT ¸Þ½ÃÁö, WPARAM wParam, LPARAM lParam);

	static void UpdateMouseEvent(UINT mouseMessage, WPARAM deltaValue, D3DMouseEvent* mouseEvent);
	static void UpdateKeyboardEvent(UINT keyboardMessage, WPARAM keyValue, D3DKeyboardEvent* keyboardEvent);
	static void UpdateWindowEvent(UINT windowMessage, WPARAM windowValue, D3DWindowEvent* windowEvent);
public:
	D3DApplication(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPWSTR    lpCmdLine,
		int       nCmdShow);
	virtual ~D3DApplication();


	void Add(D3DObject* obj);
	void Remove(D3DObject* obj);
	inline virtual const std::string GetApplicationName() = 0;
	int Run();
	void Close();
protected:
	virtual bool Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

protected:
	HINSTANCE	m_hInstance;
	HINSTANCE	m_hPrevInstance;
	LPWSTR		m_lpCmdLine;
	int			m_nCmdShow;

	bool		m_isRunning;
	HWND		m_hWnd;
	WNDCLASSEX	m_winInfo;
	RECT		m_rectangle;
	
	const float	m_framePerSec = 1 / 60.0f;
protected:
	std::unordered_map<D3DObject*, D3DObject*> m_children;
	D3DEventDispatcher* m_eventDispatcher;

	
	friend class D3DManager;
};


