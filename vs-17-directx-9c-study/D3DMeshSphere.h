/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-17 오후 6:17:31
 * Description : 구형 오브젝트
 */

#pragma once

#include <d3dx9mesh.h>

#include "D3DVertex.h"
#include "D3DMeshObject.h"
#include "D3DMacro.h"

class D3DMeshSphere : public D3DMeshObject
{
	CREATE_D3D_MESH_OBJECT_CONSTRUCTOR_WITH_1PARAM(D3DMeshSphere, float, radious, m_radious);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DMeshSphere);
private:
	LPD3DXMESH					m_mesh;
protected:
	void OnInit() override;
	void OnRender() override;
	void OnUpdate() override {}
	void OnRelease() override {}
};
