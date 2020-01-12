#pragma once

#include "D3DEventListener.h"
#include "D3DEvent.h"
#include "Singleton.h"

#include <unordered_map>


class D3DEventDispatcher final
{
	typedef std::string ListenerID;
private:
	D3DEventDispatcher(){}
	~D3DEventDispatcher();

	ListenerID _getListenerID(D3DEvent::Type eventType);
public:
	void AddEventListener(D3DEventListener* listener);
	void DispatchEvent(D3DEvent* event);
private:
	std::unordered_map<ListenerID, std::vector<D3DEventListener*>> m_eventListeners;
	friend class D3DApplication;
};