#pragma once

#include <d3d9.h>
#include <vector>

#include "D3DVertex.h"
#include "D3DVertexObject.h"
#include "D3DMacro.h"

class D3DAxis : public D3DObject
{
	CREATE_D3DOBJECT_CONSTRUCTOR_WITH_1PARAM(D3DAxis, float, length, m_length);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DAxis);
private:
	std::vector<D3DVertex3D> m_vertexes;
	LPDIRECT3DVERTEXBUFFER9  m_pVertextBuffer;
protected:
	virtual void OnInit() override;
	virtual void OnRender()override;
	virtual void OnRelease() override;
	virtual void OnUpdate()override {}
};

