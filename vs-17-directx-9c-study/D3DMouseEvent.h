#pragma once

#include "D3DEvent.h"

class D3DMouseEvent final : public D3DEvent
{
public:
	enum class MouseEventType
	{
		MOUSE_NONE,
		MOUSE_DOWN,
		MOUSE_UP,
		MOUSE_MOVE,
		MOUSE_SCROLL,
	};

	enum class MouseButton
	{
		BUTTON_UNSET = -1,
		BUTTON_LEFT = 0,
		BUTTON_RIGHT = 1,
		BUTTON_MIDDLE = 2,
	};
public:
	D3DMouseEvent(MouseEventType type) :
		D3DEvent(Type::MOUSE),
		m_cursorPositionX(0.0f),
		m_cursorPositionY(0.0f)
	{
	}
public:
	MouseEventType getMouseEventType() { return m_mouseEventType;}
	MouseButton getMouseButton() { return m_mouseButton; }

private:
	MouseEventType m_mouseEventType;
	MouseButton m_mouseButton;
	float m_cursorPositionX;
	float m_cursorPositionY;
};