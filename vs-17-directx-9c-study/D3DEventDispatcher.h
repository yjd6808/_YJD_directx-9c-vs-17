#pragma once

#include "D3DEventListener.h"
#include "Singleton.h"

#include <unordered_map>

extern class D3DMouseEvent;
extern class D3DKeyboardEvent;

class D3DEventDispatcher final
{
private:
	D3DEventDispatcher(){}
	~D3DEventDispatcher();
private:
	void OnMouseUpdate(D3DMouseEvent* mouseEvent);
	void OnKeyboardUpdate(D3DKeyboardEvent* keyEvent);
private:
	std::unordered_map<D3DEventListener*, D3DEventListener*> listeners;

	friend class D3DApplication;
};