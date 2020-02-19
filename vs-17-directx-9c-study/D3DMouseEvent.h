#pragma once

#include "D3DEvent.h"
#include "D3DPoint.h"

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
	D3DMouseEvent() :
		D3DEvent(Type::MOUSE),
		m_mouseEventType(MouseEventType::MOUSE_NONE),
		m_mouseButton(MouseButton::BUTTON_UNSET)
	{
	}
public:
	MouseEventType GetMouseEventType() { return m_mouseEventType;}
	MouseButton GetMouseButton() { return m_mouseButton; }
	int GelScrollDeltaValue() { return m_scrollDeltaValue;  }
	D3DPoint2D GetMousePosition(){ return m_cursorPosition; }
private:
	MouseEventType m_mouseEventType;
	MouseButton m_mouseButton;
	D3DPoint2D m_cursorPosition;
	int m_scrollDeltaValue;

	friend class D3DApplication;
};