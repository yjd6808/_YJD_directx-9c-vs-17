#pragma once

#include "D3DEvent.h"
#include "D3DSize.h"
#include "D3DPoint.h"

class D3DWindowEvent : public D3DEvent
{
public:
	enum class WindowEventType
	{
		MOVE,
		RESIZE,
		MINIMIZE,
		MAXIMIZE,
		EXIT
	};

	//���� ���� ������ ����; ������ ���� ���� ���°Ÿ� �ϴ�.. ����
	//- 2020�� 1�� 11�� ����� �������Ʈ â������ϳ� ���� ��糯 ��鼭 �ڵ��� �ۼ���

	//�ƴϴ�.. �׷��� �ؾ��Ѵ�..
	//- 2020�� 1�� 12�� �Ͽ���
	D3DWindowEvent() :
		D3DEvent(D3DEvent::Type::WINDOW)
	{
	}

	WindowEventType GetWindowEventType() { return m_windowEventType; }
	D3DSize GetSize()	{ return m_size; }
	D3DPoint2D GetPosition() { return m_point; }
private:
	WindowEventType m_windowEventType;
	D3DSize m_size;
	D3DPoint2D m_point;

	friend class D3DApplication;
};