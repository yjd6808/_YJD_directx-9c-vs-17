#pragma once

#include <functional>

extern class D3DEvent;

class D3DEventListener
{
	typedef std::string ListenerID;
public:
	enum class Type
	{
		MOUSE,
		KEYBOARD,
		WINDOW
	};
public:
	D3DEventListener(Type type, ListenerID listenerId) :
		m_type(type),
		m_listenerID(listenerId)
	{
	}
	~D3DEventListener() {}

	Type GetType() { return m_type; }
	ListenerID GetListenerID() { return m_listenerID; }
protected:
	virtual bool OnInit() = 0;
protected:
	ListenerID m_listenerID;
	std::function<void(D3DEvent*)> m_callback;
	Type m_type;
};
