#pragma once

#include <vector>
#include <d3dx9mesh.h>

#include "D3DVertex.h"
#include "D3DVertexObject.h"
#include "D3DMacro.h"

class D3DCube : public D3DVertexObject
{
	CREATE_D3D_VERTEX_OBJECT_CONSTRUCTOR_WITH_1PARAM(D3DCube, float, length, m_length);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DCube);
private:
	std::vector<D3DVertex3D>	m_vertexes;
	LPDIRECT3DVERTEXBUFFER9		m_pVertextBuffer;
	LPDIRECT3DINDEXBUFFER9		m_pIndexBuffer;
public:
	D3DPoint3D					m_min;
	D3DPoint3D					m_max;
protected:
	virtual void ChangeVertexesColor() override;
	virtual void OnInit() override;
	virtual void OnRender() override;
	virtual void OnRelease() override;
	virtual void OnUpdate() override {}
};

