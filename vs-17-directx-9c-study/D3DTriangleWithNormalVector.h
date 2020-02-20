/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-18 오전 10:46:49
 * Description : 
 */

#include <d3dx9mesh.h>

#include "D3DVertex.h"
#include "D3DVertexObject.h"
#include "D3DMacro.h"

#include <vector>

#pragma once

class D3DTriangleWithNormalVector : public D3DVertexObject
{
	CREATE_D3D_VERTEX_OBJECT_CONSTRUCTOR_WITH_1PARAM(D3DTriangleWithNormalVector, float, length, m_length);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DTriangleWithNormalVector);
private:
	std::vector<D3DVertex3D>	m_vertexes;
	LPDIRECT3DVERTEXBUFFER9		m_pVertextBuffer;
protected:
	virtual void ChangeVertexesColor() override;
	virtual void OnInit() override;
	virtual void OnRender() override;
	virtual void OnRelease() override;
	virtual void OnUpdate() override {}
};
