#pragma once

#include <vector>
#include <d3dx9mesh.h>

#include "D3DVertex.h"
#include "D3DObject.h"
#include "D3DMacro.h"

class D3DCube : public D3DObject
{
	CREATE_D3DOBJECT_CONSTRUCTOR_WITH_1PARAM(D3DCube, float, length, m_length);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DCube);
private:
	std::vector<D3DVertex3D>	m_vertexes;
	LPDIRECT3DVERTEXBUFFER9		m_pVertextBuffer;
	LPDIRECT3DINDEXBUFFER9		m_pIndexBuffer;
	LPD3DXMESH					m_mesh;

public:
	D3DPoint3D					m_min;
	D3DPoint3D					m_max;
protected:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();
public :
	bool isCollided(D3DCube* otherCube);
};

