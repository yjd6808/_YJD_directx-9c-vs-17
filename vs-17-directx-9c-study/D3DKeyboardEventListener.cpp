#include "D3DKeyboardEventListener.h"

#include "D3DKeyboardEvent.h"
#include "D3DMacro.h"

#include <functional>
#include <Windows.h>

const std::string D3DKeyboardEventListener::LISTENER_ID = "__d3d_keyboardListener";
const std::unordered_map<unsigned, D3DKeyboardEvent::KeyCode>  D3DKeyboardEventListener::KEY_MAP = 
{
	{	0x10,			D3DKeyboardEvent::KeyCode::KEY_LEFT_SHIFT	},
	{	0x11,			D3DKeyboardEvent::KeyCode::KEY_LEFT_CTRL	},
	{	0x12,			D3DKeyboardEvent::KeyCode::KEY_LEFT_ALT		},
	{	VK_F1,			D3DKeyboardEvent::KeyCode::KEY_F1			},
	{	VK_F2,			D3DKeyboardEvent::KeyCode::KEY_F2			},
	{	VK_F3,			D3DKeyboardEvent::KeyCode::KEY_F3			},
	{	VK_F4,			D3DKeyboardEvent::KeyCode::KEY_F4			},
	{	VK_F5,			D3DKeyboardEvent::KeyCode::KEY_F5			},
	{	VK_F6,			D3DKeyboardEvent::KeyCode::KEY_F6			},
	{	VK_F7,			D3DKeyboardEvent::KeyCode::KEY_F7			},
	{	VK_F8,			D3DKeyboardEvent::KeyCode::KEY_F8			},
	{	VK_F9,			D3DKeyboardEvent::KeyCode::KEY_F9			},
	{	VK_F10,			D3DKeyboardEvent::KeyCode::KEY_F10			},
	{	VK_F11,			D3DKeyboardEvent::KeyCode::KEY_F11			},
	{	VK_F12,			D3DKeyboardEvent::KeyCode::KEY_F12			},
	{	VK_NUMPAD0,		D3DKeyboardEvent::KeyCode::KEY_NUMPAD_0		},
	{	VK_NUMPAD1,		D3DKeyboardEvent::KeyCode::KEY_NUMPAD_1		},
	{	VK_NUMPAD2,		D3DKeyboardEvent::KeyCode::KEY_NUMPAD_2		},
	{	VK_NUMPAD3,		D3DKeyboardEvent::KeyCode::KEY_NUMPAD_3		},
	{	VK_NUMPAD4,		D3DKeyboardEvent::KeyCode::KEY_NUMPAD_4		},
	{	VK_NUMPAD5,		D3DKeyboardEvent::KeyCode::KEY_NUMPAD_5		},
	{	VK_NUMPAD6,		D3DKeyboardEvent::KeyCode::KEY_NUMPAD_6		},
	{	VK_NUMPAD7,		D3DKeyboardEvent::KeyCode::KEY_NUMPAD_7		},
	{	VK_NUMPAD8,		D3DKeyboardEvent::KeyCode::KEY_NUMPAD_8		},
	{	VK_NUMPAD9,		D3DKeyboardEvent::KeyCode::KEY_NUMPAD_9		},
	{	'0',			D3DKeyboardEvent::KeyCode::KEY_0			},
	{	'1',			D3DKeyboardEvent::KeyCode::KEY_1			},
	{	'2',			D3DKeyboardEvent::KeyCode::KEY_2			},
	{	'3',			D3DKeyboardEvent::KeyCode::KEY_3			},
	{	'4',			D3DKeyboardEvent::KeyCode::KEY_4			},
	{	'5',			D3DKeyboardEvent::KeyCode::KEY_5			},
	{	'6',			D3DKeyboardEvent::KeyCode::KEY_6			},
	{	'7',			D3DKeyboardEvent::KeyCode::KEY_7			},
	{	'8',			D3DKeyboardEvent::KeyCode::KEY_8			},
	{	'9',			D3DKeyboardEvent::KeyCode::KEY_9			},
	{	'A',			D3DKeyboardEvent::KeyCode::KEY_A			},
	{	'B',			D3DKeyboardEvent::KeyCode::KEY_B			},
	{	'C',			D3DKeyboardEvent::KeyCode::KEY_C			},
	{	'D',			D3DKeyboardEvent::KeyCode::KEY_D			},
	{	'E',			D3DKeyboardEvent::KeyCode::KEY_E			},
	{	'F',			D3DKeyboardEvent::KeyCode::KEY_F			},
	{	'G',			D3DKeyboardEvent::KeyCode::KEY_G			},
	{	'H',			D3DKeyboardEvent::KeyCode::KEY_H			},
	{	'I',			D3DKeyboardEvent::KeyCode::KEY_I			},
	{	'J',			D3DKeyboardEvent::KeyCode::KEY_J			},
	{	'K',			D3DKeyboardEvent::KeyCode::KEY_K			},
	{	'L',			D3DKeyboardEvent::KeyCode::KEY_L			},
	{	'M',			D3DKeyboardEvent::KeyCode::KEY_M			},
	{	'N',			D3DKeyboardEvent::KeyCode::KEY_N			},
	{	'O',			D3DKeyboardEvent::KeyCode::KEY_O			},
	{	'P',			D3DKeyboardEvent::KeyCode::KEY_P			},
	{	'Q',			D3DKeyboardEvent::KeyCode::KEY_Q			},
	{	'R',			D3DKeyboardEvent::KeyCode::KEY_R			},
	{	'S',			D3DKeyboardEvent::KeyCode::KEY_S			},
	{	'T',			D3DKeyboardEvent::KeyCode::KEY_T			},
	{	'U',			D3DKeyboardEvent::KeyCode::KEY_U			},
	{	'V',			D3DKeyboardEvent::KeyCode::KEY_V			},
	{	'W',			D3DKeyboardEvent::KeyCode::KEY_W			},
	{	'X',			D3DKeyboardEvent::KeyCode::KEY_X			},
	{	'Y',			D3DKeyboardEvent::KeyCode::KEY_Y			},
	{	'Z',			D3DKeyboardEvent::KeyCode::KEY_Z			},
	{	VK_RETURN,		D3DKeyboardEvent::KeyCode::KEY_ENTER		},
	{	VK_SPACE,		D3DKeyboardEvent::KeyCode::KEY_SPACE		},
	{	VK_INSERT,		D3DKeyboardEvent::KeyCode::KEY_INSERT		},
	{	VK_HOME,		D3DKeyboardEvent::KeyCode::KEY_HOME			},
	{	VK_PRIOR,		D3DKeyboardEvent::KeyCode::KEY_PAGEUP		},
	{	VK_NEXT,		D3DKeyboardEvent::KeyCode::KEY_PAGEDOWN		},
	{	VK_DELETE,		D3DKeyboardEvent::KeyCode::KEY_DELETE		},
	{	VK_END,			D3DKeyboardEvent::KeyCode::KEY_END		},
};

#include <iostream>

using namespace std;

D3DKeyboardEventListener::D3DKeyboardEventListener() :
	D3DEventListener(Type::KEYBOARD, LISTENER_ID),
	onKeyPressed(nullptr),
	onKeyReleased(nullptr)
{
	
	OnInit();
}


void D3DKeyboardEventListener::OnInit()
{
	m_callback = D3DCALLBACK_1(D3DKeyboardEventListener::HandleEvent, this);
}

void D3DKeyboardEventListener::HandleEvent(D3DEvent * event)
{
	auto keyboardEvent = static_cast<D3DKeyboardEvent*>(event);

	if (keyboardEvent->GetKeyCode() == D3DKeyboardEvent::KeyCode::KEY_NONE)
		return;

	if (keyboardEvent->IsPressed()) {
		if (onKeyPressed != nullptr)
			onKeyPressed(keyboardEvent);
	}
	else {
		if (onKeyReleased != nullptr)
			onKeyReleased(keyboardEvent);
	}
}

