#include "D3DEventDispatcher.h"

#include "D3DMouseEvent.h"
#include "D3DKeyboardEventListener.h"
#include "D3DMouseEventListener.h"

#include <iostream>

using namespace std;

D3DEventDispatcher::~D3DEventDispatcher()
{
}

void D3DEventDispatcher::AddEventListener(D3DEventListener * listener)
{
	auto it = m_eventListeners.find(listener->GetListenerID());
	if (it != m_eventListeners.end()) {
		it->second.push_back();
	}
}

void D3DEventDispatcher::DispatchEvent(D3DEvent * event)
{
}
