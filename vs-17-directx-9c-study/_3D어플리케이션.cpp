#include "_3D어플리케이션.h"

void _3D어플리케이션::OnInit()
{
	this->Add(m_objectFactory->CreateAxis(5.0f));
	this->Add(m_objectFactory->CreateCube(5.0f));
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
