#pragma once

#include "D3DApplication3D.h"

#include "D3DCube.h"

class _3D���ø����̼� : public D3DApplication3D
{
	CREATE_D3DAPPLICATION3D_CONSTRUCTOR(_3D���ø����̼�);
protected:
	void OnInit() override;
	void OnUpdate() override;
	void OnRender() override;
	void OnRelease() override;

private:
	D3DCube* cube;
	D3DObject* obj;
};

