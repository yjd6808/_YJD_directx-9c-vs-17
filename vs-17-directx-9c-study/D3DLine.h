#pragma once

#include <d3d9.h>
#include <vector>

#include "D3DVertex.h"
#include "D3DObject.h"
#include "D3DMacro.h"

class D3DLine : public D3DObject
{
	CREATE_D3DOBJECT_CONSTRUCTOR_WITH_2PARAM(D3DLine, D3DPoint3D, start, m_start, D3DPoint3D, end, m_end);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DLine);
private:
	std::vector<D3DVertex3D> m_vertexes;
	LPDIRECT3DVERTEXBUFFER9  m_pVertextBuffer;
protected:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();
};

