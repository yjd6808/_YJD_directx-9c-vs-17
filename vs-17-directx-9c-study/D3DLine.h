/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-19 오전 11:33:06
 */


#pragma once

#include <d3d9.h>
#include <vector>

#include "D3DVertexObject.h"
#include "D3DVertex.h"
#include "D3DMacro.h"

class D3DLine : public D3DVertexObject
{
	CREATE_D3D_VERTEX_OBJECT_CONSTRUCTOR_WITH_2PARAM(D3DLine, D3DPoint3D, start, m_start, D3DPoint3D, end, m_end);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DLine);
private:
	std::vector<D3DVertex3D> m_vertexes;
	LPDIRECT3DVERTEXBUFFER9  m_pVertextBuffer;
protected:
	virtual void ChangeVertexesColor() override;
	virtual void OnInit() override;
	virtual void OnRender() override;
	virtual void OnRelease() override;
	virtual void OnUpdate() override {}
};

