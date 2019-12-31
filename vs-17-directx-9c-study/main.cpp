#include "D3DManager.h"
#include "_3D어플리케이션.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPWSTR    lpCmdLine, 
	_In_ int       nCmdShow) {
	return D3DManager::StartApplication(new _3D어플리케이션(hInstance, hPrevInstance, lpCmdLine, nCmdShow));
}