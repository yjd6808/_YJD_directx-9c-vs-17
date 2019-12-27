#include "D3DEdu01.h"
#include "common.h"

void D3DEdu01::OnUpdate()
{
}

void D3DEdu01::OnRelease()
{
	triangle.OnRelease();
}

void D3DEdu01::OnRender()
{
	triangle.OnRender();
}

void D3DEdu01::OnInit()
{
	triangle.OnInit(m_pD3DDevice);
}

D3DEdu01::D3DEdu01()
{
}

D3DEdu01::~D3DEdu01()
{
}
