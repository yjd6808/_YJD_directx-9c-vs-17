#include "D3DManager.h"
#include "_3D���ø����̼�.h"
#include "D3DConsole.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPWSTR    lpCmdLine, 
	_In_ int       nCmdShow) {

	D3DConsole::Initialize();
	D3DConsole::MoveTo(0, 0);
	D3DConsole::SetWidth(300);
	D3DConsole::SetHeight(200);

	return D3DManager::StartApplication(new _3D���ø����̼�(hInstance, hPrevInstance, lpCmdLine, nCmdShow));
}