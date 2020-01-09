#pragma once

#include "D3DEventListener.h"
#include "D3DMouseEvent.h"
#include <functional>

class D3DMouseEventListener final : public D3DEventListener
{
private:
	void OnInit() override;
	void OnUpdate() override;
private:
	void OnMouseCl(D3DMouseEvent* event);
public:
	std::function<void(D3DMouseEvent*)> onMouseDown;
	std::function<void(D3DMouseEvent*)> onMousePressed;
	std::function<void(D3DMouseEvent*)> onMouseUp;
};
