#pragma once

#include "D3DEventListener.h"
#include "D3DWindowEvent.h"

#include <functional>

class D3DWindowEventListener final : public D3DEventListener
{
public:
	D3DWindowEventListener() :
		D3DEventListener(Type::WINDOW)
	{
	}
private:
	void OnInit() override;
	void OnUpdate() override;
public:
	std::function<void(D3DWindowEvent*)> onWindowExit;
	std::function<void(D3DWindowEvent*)> onWindowMove;
	std::function<void(D3DWindowEvent*)> onWindowResize;
	std::function<void(D3DWindowEvent*)> onWindowMaxiMize;
	std::function<void(D3DWindowEvent*)> onWindowMiniMize;;
};
