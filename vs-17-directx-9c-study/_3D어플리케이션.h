#pragma once

#include "D3DApplication3D.h"

#include "D3DCube.h"
#include "D3DMeshCube.h"
#include "D3DSphere.h"
#include "D3DPlane.h"
#include <vector>

class _3D어플리케이션 : public D3DApplication3D
{
	CREATE_D3DAPPLICATION3D_CONSTRUCTOR(_3D어플리케이션);
protected:
	void OnInit() override;
	void OnUpdate() override;
private:
	D3DMeshCube* cubeLeft;
	D3DMeshCube* cubeRight;

	D3DSphere* sphereLeft;
	D3DSphere* sphereRight;

	D3DObject* obj;
	D3DPlane* plane;
	std::vector<D3DKeyboardEvent::KeyCode> m_keyCodeVec;
};

