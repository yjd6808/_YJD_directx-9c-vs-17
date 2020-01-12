#pragma once

#include "D3DEventListener.h"
#include "D3DWindowEvent.h"
#include "D3DKeyboardEvent.h"

#include <functional>
#include <unordered_map>

class D3DKeyboardEventListener final : public D3DEventListener
{
	typedef std::string ListenerID;
	typedef unsigned VKKey;
	typedef D3DKeyboardEvent::KeyCode D3DkeyCode;
	typedef std::unordered_map<VKKey, D3DkeyCode> KeyMap;
public:
	static const ListenerID LISTENER_ID;
	static const KeyMap KEY_MAP;
	D3DKeyboardEventListener();
private:
	void OnInit() override;
	void HandleEvent(D3DEvent* event) override;
public:
	std::function<void(D3DKeyboardEvent*)> onKeyPressed;
	std::function<void(D3DKeyboardEvent*)> onKeyReleased;
};
