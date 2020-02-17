/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-17 오후 6:17:31
 * Description : 구형 오브젝트
 */

#pragma once

#include <d3dx9mesh.h>

#include "D3DVertex.h"
#include "D3DObject.h"
#include "D3DMacro.h"

class D3DSphere : public D3DObject
{
	CREATE_D3DOBJECT_CONSTRUCTOR_WITH_1PARAM(D3DSphere, float, radious, m_radious);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DSphere);
private:
	LPD3DXMESH					m_mesh;
protected:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();
public:
	bool isCollided(D3DSphere* otherCube);
};
