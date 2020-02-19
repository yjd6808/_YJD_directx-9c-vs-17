#include "_3D_���ð���.h"

#include <iostream>

using namespace std;

void _3D_���ð���::OnInit()
{
	D3DAxis* axis = m_objectFactory->CreateAxis(1000.0f);
	this->Add(axis);

	D3DPlane* ground = m_objectFactory->CreatePlane(20, 10, 3.0f);
	ground->SetSolid(true);
	this->Add(ground);
	
	//�÷��̾� ��ü ����
	D3DMouseEventListener* listener = new D3DMouseEventListener();
	listener->onMouseMove = [this](D3DMouseEvent* event)
	{

	};
	listener->onMouseDown = [](D3DMouseEvent* event)
	{
		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_LEFT)
			cout << "���� ��ư Ŭ��" << endl;

		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_RIGHT)
			cout << "������ ��ư Ŭ��" << endl;

		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_MIDDLE)
			cout << "��� ��ư Ŭ��" << endl;
	};
	listener->onMouseUp = [](D3DMouseEvent* event)
	{
		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_LEFT)
			cout << "���� ��ư ��" << endl;

		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_RIGHT)
			cout << "������ ��ư ��" << endl;

		if (event->GetMouseButton() == D3DMouseEvent::MouseButton::BUTTON_MIDDLE)
			cout << "��� ��ư ��" << endl;
	};
	listener->onMouseScroll = [](D3DMouseEvent* event)
	{
		if (event->GelScrollDeltaValue() > 0)
			cout << "���� �ø�" << endl;
		if (event->GelScrollDeltaValue() < 0)
			cout << "���� ����" << endl;
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
		cout << "������ ������?" << endl;
	};
	windowEventListener->onWindowMaxiMize = [](D3DWindowEvent* event) {
		cout << "�ִ�ȭ �̺�Ʈ ����" << endl;
		cout << event->GetSize().width << endl;
		cout << event->GetSize().height << endl;
	};
	windowEventListener->onWindowMiniMize = [](D3DWindowEvent* event) {
		cout << "�ּ�ȭ �̺�Ʈ ����" << endl;
		cout << event->GetSize().width << endl;
		cout << event->GetSize().height << endl;
	};
	windowEventListener->onWindowMove = [](D3DWindowEvent* event) {
		cout << "����" << endl;
		cout << event->GetPosition().x << " / " << event->GetPosition().y << endl;
	};
	windowEventListener->onWindowResize = [](D3DWindowEvent* event) {
		cout << "��������" << endl;
		cout << event->GetSize().width << endl;
		cout << event->GetSize().height << endl;
	};

	//m_eventDispatcher->AddEventListener(windowEventListener);
	m_eventDispatcher->AddEventListener(listener);
	m_eventDispatcher->AddEventListener(keyboardEventListener);
}

void _3D_���ð���::OnUpdate()
{
}

void _3D_���ð���::OnInitEnd()
{
	m_camera->SetPosition(-10, 70, 0);


}
