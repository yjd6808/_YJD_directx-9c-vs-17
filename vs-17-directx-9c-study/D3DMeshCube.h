﻿/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-17 오후 5:36:38
 * Description : CreateBox함수를 사용해 생성한 큐브
 */

#pragma once

#include <d3d9.h>
#include <vector>
#include <d3dx9mesh.h>

#include "D3DVertex.h"
#include "D3DMeshObject.h"
#include "D3DMacro.h"

class D3DMeshCube : public D3DMeshObject
{
	CREATE_D3D_MESH_OBJECT_CONSTRUCTOR_WITH_1PARAM(D3DMeshCube, float, length, m_length);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DMeshCube);
private:
	LPD3DXMESH					m_mesh;
public:
	D3DPoint3D					m_min;
	D3DPoint3D					m_max;
	
protected:
	virtual void OnInit() override;
	virtual void OnRender() override;
	virtual void OnRelease() override {}
	virtual void OnUpdate() override {}
};
