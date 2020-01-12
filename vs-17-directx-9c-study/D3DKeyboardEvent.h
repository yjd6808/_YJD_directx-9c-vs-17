#pragma once

#include "D3DEvent.h"

class D3DKeyboardEvent : public D3DEvent
{
public:
	enum class KeyCode
	{
		KEY_NONE,
		KEY_LEFT_SHIFT,
		KEY_LEFT_CTRL,
		KEY_LEFT_ALT,
		KEY_RIGHT_SHIFT,
		KEY_RIGHT_CTRL,
		KEY_RIGHT_ALT,
		KEY_F1,
		KEY_F2,
		KEY_F3,
		KEY_F4,
		KEY_F5,
		KEY_F6,
		KEY_F7,
		KEY_F8,
		KEY_F9,
		KEY_F10,
		KEY_F11,
		KEY_F12,
		KEY_NUMPAD_0,
		KEY_NUMPAD_1,
		KEY_NUMPAD_2,
		KEY_NUMPAD_3,
		KEY_NUMPAD_4,
		KEY_NUMPAD_5,
		KEY_NUMPAD_6,
		KEY_NUMPAD_7,
		KEY_NUMPAD_8,
		KEY_NUMPAD_9,
		KEY_0,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		KEY_CAPITAL_A,
		KEY_CAPITAL_B,
		KEY_CAPITAL_C,
		KEY_CAPITAL_D,
		KEY_CAPITAL_E,
		KEY_CAPITAL_F,
		KEY_CAPITAL_G,
		KEY_CAPITAL_H,
		KEY_CAPITAL_I,
		KEY_CAPITAL_J,
		KEY_CAPITAL_K,
		KEY_CAPITAL_L,
		KEY_CAPITAL_M,
		KEY_CAPITAL_N,
		KEY_CAPITAL_O,
		KEY_CAPITAL_P,
		KEY_CAPITAL_Q,
		KEY_CAPITAL_R,
		KEY_CAPITAL_S,
		KEY_CAPITAL_T,
		KEY_CAPITAL_U,
		KEY_CAPITAL_V,
		KEY_CAPITAL_W,
		KEY_CAPITAL_X,
		KEY_CAPITAL_Y,
		KEY_CAPITAL_Z,
		KEY_A,
		KEY_B,
		KEY_C,
		KEY_D,
		KEY_E,
		KEY_F,
		KEY_G,
		KEY_H,
		KEY_I,
		KEY_J,
		KEY_K,
		KEY_L,
		KEY_M,
		KEY_N,
		KEY_O,
		KEY_P,
		KEY_Q,
		KEY_R,
		KEY_S,
		KEY_T,
		KEY_U,
		KEY_V,
		KEY_W,
		KEY_X,
		KEY_Y,
		KEY_Z,
		KEY_ENTER,
		KEY_ESC,
		KEY_SPACE,
		KEY_INSERT,
		KEY_HOME,
		KEY_PAGEUP,
		KEY_DELETE,
		KEY_END,
		KEY_PAGEDOWN
	};
public:
	D3DKeyboardEvent() :
		D3DEvent(D3DEvent::Type::KEYBOARD),
		m_isPressed(false)
	{
	}

	KeyCode GetKeyCode() { return m_keyCode; }
	bool IsPressed() { return m_isPressed; }
private:
	KeyCode m_keyCode;
	bool m_isPressed;

	friend class D3DApplication;
};
