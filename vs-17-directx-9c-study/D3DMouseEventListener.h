#pragma once

#include "D3DEventListener.h"
#include "D3DMouseEvent.h"

#include <functional>

class D3DMouseEventListener final : public D3DEventListener
{
public:
	D3DMouseEventListener() :
		D3DEventListener(Type::MOUSE) 
	{
	}
private:
	bool OnInit() override;
public:
	std::function<void(D3DMouseEvent*)> onMouseMove;
	std::function<void(D3DMouseEvent*)> onMouseDown;
	std::function<void(D3DMouseEvent*)> onMouseUp;
	std::function<void(D3DMouseEvent*)> onMouseScroll;
};
