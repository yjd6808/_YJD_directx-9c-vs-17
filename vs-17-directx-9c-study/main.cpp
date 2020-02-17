#include "D3DManager.h"
#include "_3D���ø����̼�.h"
#include "D3DConsole.h"

#include <iostream>
using namespace std;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPWSTR    lpCmdLine, 
	_In_ int       nCmdShow) {


	D3DConsole::Initialize();
	D3DConsole::MoveTo(0, 0);
	D3DConsole::SetWidth(300);
	D3DConsole::SetHeight(200);

	int _exitCode = D3DManager::StartApplication(new _3D���ø����̼�(hInstance, hPrevInstance, lpCmdLine, nCmdShow));
	D3DManager::ReleaseMemory();
	return _exitCode;
}