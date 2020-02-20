/*
 * @Author	: Jungdo Yun
 * @Created	: 19.12.??
 */

#pragma once

#include <d3d9.h>
#include <vector>

#include "D3DVertex.h"
#include "D3DMeshObject.h"
#include "D3DMacro.h"

class D3DPlane : public D3DMeshObject
{
	CREATE_D3D_MESH_OBJECT_CONSTRUCTOR_WITH_3PARAM(D3DPlane, int, width, m_width, int, height, m_height, float, squreSideLength, m_squreSideLength);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DPlane);
private:
	std::vector<D3DVertex3DMaterial> m_vertexes;
	LPDIRECT3DVERTEXBUFFER9  m_pVertextBuffer;
	LPDIRECT3DINDEXBUFFER9 m_pIndexBuffer;
	D3DMATERIAL9			m_material;
protected:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();
};

