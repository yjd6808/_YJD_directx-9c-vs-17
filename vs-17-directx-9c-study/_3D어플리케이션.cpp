#include "_3D���ø����̼�.h"

#include <iostream>

using namespace std;

void _3D���ø����̼�::OnInit()
{
	D3DAxis* axis = m_objectFactory->CreateAxis(15.0f);
	this->Add(axis);
	//cube = m_objectFactory->CreateCube(5.0f);
	//this->Add(cube);
	this->Add(m_objectFactory->CreatePlane(3, 2, 1.0f));
	D3DPlane* plane = m_objectFactory->CreatePlane(3, 2, 1.0f);
	plane->SetScale(0.5f, 2.0f, 3.0f);
	obj = plane;
	this->Add(plane);
	this->Add(m_objectFactory->CreatePlane(3, 2, 0.5f));
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
