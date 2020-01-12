#include "D3DMouseEventListener.h"

const std::string D3DMouseEventListener::LISTENER_ID = "__d3d_mouseListener";


D3DMouseEventListener::D3DMouseEventListener() :
	D3DEventListener(Type::MOUSE, LISTENER_ID),
	onMouseMove(nullptr),
	onMouseDown(nullptr),
	onMouseScroll(nullptr),
	onMouseUp(nullptr)
{
	if (OnInit()) {
	}
}

bool D3DMouseEventListener::OnInit()
{
	return true;
}
