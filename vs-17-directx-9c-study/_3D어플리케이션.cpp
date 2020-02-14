#include "_3D어플리케이션.h"
#include "D3DText.h"

#include <iostream>

using namespace std;

float getInternal(D3DXVECTOR2& a, D3DXVECTOR2& b) {
	return a.x * b.x + a.y + b.y;
}

float getAmount(D3DXVECTOR2 v) {
	return  pow(v.x, 2.0) + (v.y, 2.0);
}

float getDegree(D3DXVECTOR2& a, D3DXVECTOR2& b)
{
	 float rad =  getInternal(a, b) / (getAmount(a) * getAmount(b));
	 return  D3DXToDegree(acos(rad));
}

void _3D어플리케이션::OnInit()
{
	D3DXVECTOR2 a{ -1.0f,	10.0f };
	D3DXVECTOR2 b{	3.0f,	 1.0f };

	cout << getDegree(a, b) << endl;



	D3DText* text = m_objectFactory->CreateText("안녕하세요");
	text->SetPositionX(0.0f);
	text->SetPositionY(0.0f);
	text->SetColor(D3DColor::RED);
	text->SetScaleX(2.0f);
	text->SetFontSize(50);
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
	keyboardEventListener->onKeyPressed = [this](D3DKeyboardEvent* event) {
		for (auto i = m_keyCodeVec.begin(); i != m_keyCodeVec.end(); i ++) {

		}

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
	//m_eventDispatcher->AddEventListener(listener);
	m_eventDispatcher->AddEventListener(keyboardEventListener);
}

void _3D어플리케이션::OnUpdate()
{
	for (int i = 0; i < m_keyCodeVec.size(); i++) {
		if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_W) {
			m_camera->SetPositionZ(m_camera->GetPositionZ() + 0.1f);
			m_camera->SetLookAtZ(m_camera->GetLookAtZ() + 0.1f);
		}
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_S) {
			m_camera->SetPositionZ(m_camera->GetPositionZ() - 0.1f);
			m_camera->SetLookAtZ(m_camera->GetLookAtZ() - 0.1f);
		}
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_D) {
			m_camera->SetPositionX(m_camera->GetPositionX() + 0.1f);
			m_camera->SetLookAtX(m_camera->GetLookAtX() + 0.1f);
		}
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_A) {
			m_camera->SetPositionX(m_camera->GetPositionX() - 0.1f);
			m_camera->SetLookAtX(m_camera->GetLookAtX() - 0.1f);
		}
	}
}

