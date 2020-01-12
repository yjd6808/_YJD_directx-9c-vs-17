#include "D3DKeyboardEventListener.h"

static const std::string _keyboardListenerID = "__d3d_keyboardListener";

D3DKeyboardEventListener::D3DKeyboardEventListener() :
	D3DEventListener(Type::KEYBOARD, _keyboardListenerID)
{
}

bool D3DKeyboardEventListener::OnInit()
{
	return true;
}

