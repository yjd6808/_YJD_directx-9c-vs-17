#pragma once

#include "D3DApplication3D.h"

#include "D3DCube.h"
#include "D3DMeshCube.h"
#include "D3DMeshSphere.h"
#include "D3DPlane.h"
#include <vector>

class _���ο�_3D���ø����̼� : public D3DApplication3D
{
	CREATE_D3DAPPLICATION3D_CONSTRUCTOR(_���ο�_3D���ø����̼�);
protected:
	void OnInit() override;
	void OnUpdate() override;
	
private:
	D3DMeshCube* cubeLeft;
	D3DMeshCube* cubeRight;

	D3DMeshSphere* sphereLeft;
	D3DMeshSphere* sphereRight;
	D3DText* testText;

	D3DTriangleWithNormalVector* triangle;

	D3DObject* hyperRectangle;

	D3DObject* texture;
	D3DPlane* plane;
	std::vector<D3DKeyboardEvent::KeyCode> m_keyCodeVec;

	inline const std::string GetApplicationName() override { return "���ο� 3D ���ø����̼�"; }
};

