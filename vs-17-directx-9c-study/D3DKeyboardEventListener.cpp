#include "D3DKeyboardEventListener.h"

#include "D3DKeyboardEvent.h"

const std::string D3DKeyboardEventListener::LISTENER_ID = "__d3d_keyboardListener";

D3DKeyboardEventListener::D3DKeyboardEventListener() :
	D3DEventListener(Type::KEYBOARD, LISTENER_ID),
	onKeyPressed(nullptr),
	onKeyReleased(nullptr)
{
	OnInit();
}

bool D3DKeyboardEventListener::OnInit()
{
	m_callback = [this](D3DEvent* event) {
		auto keyboardEvent = static_cast<D3DKeyboardEvent*>(event);
		if (keyboardEvent->IsPressed())
		{
			if (onKeyPressed != nullptr)
				onKeyPressed(keyboardEvent);
		}
		else
		{
			if (onKeyReleased != nullptr)
				onKeyReleased(keyboardEvent);
		}
	};

	return true;
}

