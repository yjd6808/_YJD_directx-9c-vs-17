#include "D3DWindowEventListener.h"

#include "D3DMacro.h"

const std::string D3DWindowEventListener::LISTENER_ID = "__d3d_windowListener";

D3DWindowEventListener::D3DWindowEventListener() :
	D3DEventListener(Type::WINDOW, LISTENER_ID)
{
	OnInit();
}

void D3DWindowEventListener::OnInit()
{
	m_callback = D3DCALLBACK_1(D3DWindowEventListener::HandleEvent, this);
}

void D3DWindowEventListener::HandleEvent(D3DEvent * event)
{
	D3DWindowEvent* windowEvent = static_cast<D3DWindowEvent*>(event);
	switch (windowEvent->GetWindowEventType())
	{
	case D3DWindowEvent::WindowEventType::EXIT:
	{
		if (onWindowExit != nullptr)
			onWindowExit(windowEvent);
	}
	break;
	case D3DWindowEvent::WindowEventType::MAXIMIZE:
	{
		if (onWindowMaxiMize != nullptr)
			onWindowMaxiMize(windowEvent);
	}
	break;
	case D3DWindowEvent::WindowEventType::MINIMIZE:
	{
		if (onWindowMiniMize != nullptr)
			onWindowMiniMize(windowEvent);
	}
	break;
	case D3DWindowEvent::WindowEventType::MOVE:
	{
		if (onWindowMove != nullptr)
			onWindowMove(windowEvent);
	}
	break;
	case D3DWindowEvent::WindowEventType::RESIZE:
	{
		if (onWindowResize != nullptr)
			onWindowResize(windowEvent);
	}
	break;
	}
}
