#include "D3DMouseEventListener.h"

#include "D3DMacro.h"

const std::string D3DMouseEventListener::LISTENER_ID = "__d3d_mouseListener";


D3DMouseEventListener::D3DMouseEventListener() :
	D3DEventListener(Type::MOUSE, LISTENER_ID),
	onMouseMove(nullptr),
	onMouseDown(nullptr),
	onMouseScroll(nullptr),
	onMouseUp(nullptr)
{
	OnInit();
}

void D3DMouseEventListener::OnInit()
{
	m_callback = D3DCALLBACK_1(D3DMouseEventListener::HandleEvent, this);
}

void D3DMouseEventListener::HandleEvent(D3DEvent * event)
{
	D3DMouseEvent* mouseEvent = static_cast<D3DMouseEvent*>(event);
	switch (mouseEvent->GetMouseEventType())
	{
	case D3DMouseEvent::MouseEventType::MOUSE_MOVE: 
	{
		if (onMouseMove != nullptr)
			onMouseMove(mouseEvent);
	}
	break;
	case D3DMouseEvent::MouseEventType::MOUSE_DOWN:
	{
		if (onMouseDown != nullptr)
			onMouseDown(mouseEvent);
	}
	break;
	case D3DMouseEvent::MouseEventType::MOUSE_UP:
	{
		if (onMouseUp != nullptr)
			onMouseUp(mouseEvent);
	}
	break;
	case D3DMouseEvent::MouseEventType::MOUSE_SCROLL:
	{
		if (onMouseScroll != nullptr)
			onMouseScroll(mouseEvent);
	}
	break;
	case D3DMouseEvent::MouseEventType::MOUSE_NONE:
		//抗寇贸府 1
		break;
	default:
		//抗寇贸府 2
		break;
	}
}
