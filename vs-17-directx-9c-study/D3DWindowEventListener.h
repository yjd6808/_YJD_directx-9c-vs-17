#pragma once

#include "D3DEventListener.h"
#include "D3DWindowEvent.h"

#include <functional>

class D3DWindowEventListener final : public D3DEventListener
{
	typedef std::string ListenerID;
	
public:
	static const ListenerID LISTENER_ID;
	D3DWindowEventListener();
private:
	void OnInit() override;
	void HandleEvent(D3DEvent* event) override;
public:
	std::function<void(D3DWindowEvent*)> onWindowExit;
	std::function<void(D3DWindowEvent*)> onWindowMove;
	std::function<void(D3DWindowEvent*)> onWindowResize;
	std::function<void(D3DWindowEvent*)> onWindowMaxiMize;
	std::function<void(D3DWindowEvent*)> onWindowMiniMize;;
};
