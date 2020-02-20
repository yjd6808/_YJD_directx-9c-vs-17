/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-19 오후 4:54:40
 * Description : 직사각형 모양의 오브젝트
 */

#include <vector>
#include <d3dx9mesh.h>

#include "D3DVertex.h"
#include "D3DVertexObject.h"
#include "D3DMacro.h"

#pragma once

class D3DHyperRectangle : public D3DVertexObject
{
	CREATE_D3D_VERTEX_OBJECT_CONSTRUCTOR_WITH_3PARAM(D3DHyperRectangle, float, length, m_length, float, depth, m_depth, float, height, m_height);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DHyperRectangle);
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
	virtual void OnUpdate() {};
};

