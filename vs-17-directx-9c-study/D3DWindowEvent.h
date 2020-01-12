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

	//아후 적기 귀찮아 ㅋㅋ; 언제가 쓸때 하자 끄는거만 일단.. ㅋㅋ
	//- 2020년 1월 11일 토요일 마상소프트 창립기념일날 쉬고 토욜날 놀면서 코딩중 작성함

	//아니다.. 그래도 해야한다..
	//- 2020년 1월 12일 일요일
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