#pragma once

#include "D3DEventListener.h"
#include "D3DMouseEvent.h"

#include <functional>

class D3DMouseEventListener final : public D3DEventListener
{
	typedef std::string ListenerID;
public:
	static const ListenerID LISTENER_ID;
	D3DMouseEventListener();
private:
	void OnInit() override;
	void HandleEvent(D3DEvent* event) override;
public:
	std::function<void(D3DMouseEvent*)> onMouseMove;
	std::function<void(D3DMouseEvent*)> onMouseDown;
	std::function<void(D3DMouseEvent*)> onMouseUp;
	std::function<void(D3DMouseEvent*)> onMouseScroll;
};
