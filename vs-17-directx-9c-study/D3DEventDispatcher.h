#pragma once

#include "D3DEventListener.h"
#include "Singleton.h"

#include <unordered_map>

extern class D3DMouseEvent;
extern class D3DKeyboardEvent;
extern class D3DMouseEventListener;
extern class D3DKeyboardEventListener;

class D3DEventDispatcher final
{
	typedef std::string ListenerID;
private:
	D3DEventDispatcher(){}
	~D3DEventDispatcher();
public:
	void AddEventListener(D3DEventListener* listener);
	void DispatchEvent(D3DEvent* event);
private:
	std::unordered_map<ListenerID, std::vector<D3DEventListener*>> m_eventListeners;
	friend class D3DApplication;
};