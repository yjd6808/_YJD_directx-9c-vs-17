#include "_3D_슈팅게임.h"

#include <iostream>

using namespace std;

void _3D_슈팅게임::OnInit()
{
	D3DAxis* axis = m_objectFactory->CreateAxis(1000.0f);
	this->Add(axis);

	D3DPlane* ground = m_objectFactory->CreatePlane(20, 10, 3.0f);
	ground->SetSolid(true);
	this->Add(ground);
	
	//플레이어 객체 생성
	D3DMouseEventListener* listener = new D3DMouseEventListener();
	listener->onMouseMove = [this](D3DMouseEvent* event)
	{

	};
	listener->onMouseDown = [](D3DMouseEvent* event)
	{
		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_LEFT)
			cout << "왼쪽 버튼 클릭" << endl;

		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_RIGHT)
			cout << "오른쪽 버튼 클릭" << endl;

		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_MIDDLE)
			cout << "가운데 버튼 클릭" << endl;
	};
	listener->onMouseUp = [](D3DMouseEvent* event)
	{
		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_LEFT)
			cout << "왼쪽 버튼 땜" << endl;

		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_RIGHT)
			cout << "오른쪽 버튼 땜" << endl;

		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_MIDDLE)
			cout << "가운데 버튼 땜" << endl;
	};
	listener->onMouseScroll = [](D3DMouseEvent* event)
	{
		if (event->GelScrollDeltaValue() > 0)
			cout << "휠을 올림" << endl;
		if (event->GelScrollDeltaValue() < 0)
			cout << "휠을 내림" << endl;
	};

	D3DKeyboardEventListener* keyboardEventListener = new D3DKeyboardEventListener();
	keyboardEventListener->onKeyPressed = [this](D3DKeyboardEvent* event) {

		auto iter = std::find(m_keyCodeVec.begin(), m_keyCodeVec.end(), event->GetKeyCode());
		if (iter == m_keyCodeVec.end())
			m_keyCodeVec.push_back(event->GetKeyCode());
	};
	keyboardEventListener->onKeyReleased = [this](D3DKeyboardEvent* event) {
		for (auto i = m_keyCodeVec.begin(); i != m_keyCodeVec.end();) {
			if ((*i) == event->GetKeyCode())
				i = m_keyCodeVec.erase(i);
			else
				i++;

		}
	};

	D3DWindowEventListener* windowEventListener = new D3DWindowEventListener();
	windowEventListener->onWindowExit = [](D3DWindowEvent* event) {
		cout << "윈도우 끌려고?" << endl;
	};
	windowEventListener->onWindowMaxiMize = [](D3DWindowEvent* event) {
		cout << "최대화 이벤트 감지" << endl;
		cout << event->GetSize().width << endl;
		cout << event->GetSize().height << endl;
	};
	windowEventListener->onWindowMiniMize = [](D3DWindowEvent* event) {
		cout << "최소화 이벤트 감지" << endl;
		cout << event->GetSize().width << endl;
		cout << event->GetSize().height << endl;
	};
	windowEventListener->onWindowMove = [](D3DWindowEvent* event) {
		cout << "무브" << endl;
		cout << event->GetPosition().x << " / " << event->GetPosition().y << endl;
	};
	windowEventListener->onWindowResize = [](D3DWindowEvent* event) {
		cout << "리사이즈" << endl;
		cout << event->GetSize().width << endl;
		cout << event->GetSize().height << endl;
	};

	//m_eventDispatcher->AddEventListener(windowEventListener);
	m_eventDispatcher->AddEventListener(listener);
	m_eventDispatcher->AddEventListener(keyboardEventListener);
}

void _3D_슈팅게임::OnUpdate()
{
}

void _3D_슈팅게임::OnInitEnd()
{
	m_camera->SetPosition(-10, 70, 0);


}
