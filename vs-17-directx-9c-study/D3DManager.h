#pragma once

#include <string>
#include <Windows.h>

extern class D3DApplication;

class D3DManager 
{
public:
	int RunApplication();
public:
	D3DManager(D3DApplication* application);
	~D3DManager();
public:
	static D3DManager* s_applicationInstance;

	static int StartApplication(D3DApplication* application);
protected:
	D3DApplication* m_application;
};


