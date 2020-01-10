#pragma once

class D3DEvent
{
public:
	enum class Type
	{
		KEYBOARD,
		MOUSE
	};

	D3DEvent(Type type) :
		m_type(type) 
	{
	}
protected:
	Type m_type;
};