#pragma once

#include "D3DEventListener.h"
#include "D3DWindowEvent.h"

#include <functional>

class D3DKeyboardEventListener final : public D3DEventListener
{

public:
	D3DKeyboardEventListener();
private:
	bool OnInit() override;
public:
	std::function<void(D3DWindowEvent*)> onKeyPressed;
	std::function<void(D3DWindowEvent*)> onKeyReleased;
private:
	bool m_isPressed;
};
