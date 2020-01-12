#pragma once

#include "D3DEventListener.h"
#include "D3DWindowEvent.h"

#include <functional>

class D3DKeyboardEventListener final : public D3DEventListener
{
	typedef std::string ListenerID;
public:
	static const ListenerID LISTENER_ID;
	D3DKeyboardEventListener();
private:
	bool OnInit() override;
public:
	std::function<void(D3DKeyboardEvent*)> onKeyPressed;
	std::function<void(D3DKeyboardEvent*)> onKeyReleased;
};
