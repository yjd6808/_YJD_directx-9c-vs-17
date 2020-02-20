#include "D3DVertexObject.h"

void D3DVertexObject::ChangeVertexesColor()
{
}

void D3DVertexObject::SetVertexColor(DWORD color)
{
	m_vertexColor = color;
	ChangeVertexesColor();
}
