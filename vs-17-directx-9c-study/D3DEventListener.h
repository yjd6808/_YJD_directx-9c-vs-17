#pragma once

#include <functional>

extern class D3DEvent;

class D3DEventListener
{
public:
	enum class Type
	{
		MOUSE,
		KEYBOARD
	};
public:
	D3DEventListener(Type type) :
		m_type(type)
	{
	}
	~D3DEventListener() {}
protected:
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
protected:
	std::function<void(D3DEvent*)> m_callback;
	Type m_type;
};
