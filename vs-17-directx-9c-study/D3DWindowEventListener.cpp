#include "D3DWindowEventListener.h"

const std::string D3DWindowEventListener::LISTENER_ID = "__d3d_windowListener";

D3DWindowEventListener::D3DWindowEventListener() :
	D3DEventListener(Type::WINDOW, LISTENER_ID)
{
}

bool D3DWindowEventListener::OnInit()
{
	return true;
}
