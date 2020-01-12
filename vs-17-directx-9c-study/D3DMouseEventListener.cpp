#include "D3DMouseEventListener.h"

static const std::string _mouseListenerID = "__d3d_mouseListener";


D3DMouseEventListener::D3DMouseEventListener() :
	D3DEventListener(Type::MOUSE, _mouseListenerID)
{
}

bool D3DMouseEventListener::OnInit()
{
	return true;
}
