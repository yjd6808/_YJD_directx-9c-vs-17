#include "D3DEventDispatcher.h"

#include "D3DMouseEvent.h"
#include "D3DKeyboardEventListener.h"
#include "D3DMouseEventListener.h"
#include "D3DEvent.h"

#include <iostream>

using namespace std;



D3DEventDispatcher::~D3DEventDispatcher()
{
}

std::string D3DEventDispatcher::_getListenerID(D3DEvent::Type eventType)
{
	switch (eventType) {
	case D3DEvent::Type::KEYBOARD: return D3DKeyboardEventListener::LISTENER_ID;
	case D3DEvent::Type::MOUSE: return D3DMouseEventListener::LISTENER_ID;
	case D3DEvent::Type::WINDOW: return D3DMouseEventListener::LISTENER_ID;
	default:
		//잘못된 이벤트 예외처리
		//솔직히 들어올일 없다..
		return "";
	}
}

void D3DEventDispatcher::AddEventListener(D3DEventListener * listener)
{
	const ListenerID LISTENER_ID = listener->GetListenerID();
	auto it = m_eventListeners.find(LISTENER_ID);
	if (it != m_eventListeners.end()) 
		it->second.push_back(listener);
	else {
		m_eventListeners.insert(::make_pair(LISTENER_ID, std::vector<D3DEventListener*>()));
		m_eventListeners[LISTENER_ID].push_back(listener);
	}
}

void D3DEventDispatcher::DispatchEvent(D3DEvent * event)
{
	ListenerID listenerID =  _getListenerID(event->GetType());

	auto it = m_eventListeners.find(listenerID);
	if (it == m_eventListeners.end())
		return;

	for (auto listenerIt = it->second.begin(); listenerIt != it->second.end(); listenerIt++) {
		if ((*listenerIt)->m_callback)
			(*listenerIt)->m_callback(event);
	}
}
