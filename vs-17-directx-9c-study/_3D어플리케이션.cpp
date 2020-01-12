#include "_3D���ø����̼�.h"
#include "D3DText.h"

#include <iostream>

using namespace std;

void _3D���ø����̼�::OnInit()
{
	D3DText* text = m_objectFactory->CreateText("�ȳ��ϼ���");
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
	m_eventDispatcher->AddEventListener(listener);
}

void _3D���ø����̼�::OnUpdate()
{

}

void _3D���ø����̼�::OnRender()
{
}

void _3D���ø����̼�::OnRelease()
{
}
