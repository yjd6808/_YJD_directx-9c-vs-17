#include "_3D어플리케이션.h"
#include "D3DText.h"

#include <iostream>

using namespace std;

void _3D어플리케이션::OnInit()
{
	D3DText* text = m_objectFactory->CreateText("안녕하세요");
	text->SetPositionX(100.0f);
	text->SetPositionY(100.0f);
	text->SetColor(D3DColor::RED);
	text->SetScaleX(2.0f);
	text->SetFontSize(30);
	this->Add(text);

	D3DAxis* axis = m_objectFactory->CreateAxis(15.0f);
	axis->SetRotationX(180.9f);
	this->Add(axis);
	//cube = m_objectFactory->CreateCube(5.0f);
	//this->Add(cube);
	this->Add(m_objectFactory->CreatePlane(3, 2, 1.0f));
	D3DPlane* plane = m_objectFactory->CreatePlane(3, 2, 1.0f);
	plane->SetScale(0.5f, 2.0f, 3.0f);
	plane->SetRotationX(90.0f);
	obj = plane;
	this->Add(plane);
	this->Add(m_objectFactory->CreatePlane(3, 2, 0.5f));
	

	D3DMouseEventListener* listener = new D3DMouseEventListener();
	listener->onMouseMove = [](D3DMouseEvent* event) 
	{
		cout << "onMouseMove Occured " << endl;
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
	keyboardEventListener->onKeyPressed = [](D3DKeyboardEvent* event) {
		cout <<  static_cast<unsigned>(event->GetKeyCode()) << "키가 눌림" << endl;
	};
	keyboardEventListener->onKeyReleased = [](D3DKeyboardEvent* event) {
		cout << static_cast<unsigned>(event->GetKeyCode()) << "키가 때짐" << endl;
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


	m_eventDispatcher->AddEventListener(windowEventListener);
	//m_eventDispatcher->AddEventListener(listener);
	//m_eventDispatcher->AddEventListener(keyboardEventListener);
}

void _3D어플리케이션::OnUpdate()
{

}

void _3D어플리케이션::OnRender()
{
}

void _3D어플리케이션::OnRelease()
{
}
