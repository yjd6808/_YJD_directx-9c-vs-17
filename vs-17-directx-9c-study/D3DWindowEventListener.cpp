#include "D3DWindowEventListener.h"

static const std::string _mouseListenerID = "__d3d_mouseListener";

D3DWindowEventListener::D3DWindowEventListener() :
	D3DEventListener(Type::WINDOW, _mouseListenerID)
{
}

bool D3DWindowEventListener::OnInit()
{
	return true;
}
