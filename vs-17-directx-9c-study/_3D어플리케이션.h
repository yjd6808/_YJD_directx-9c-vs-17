#pragma once

#include "D3DApplication3D.h"

class _3D���ø����̼� : public D3DApplication3D
{
	CREATE_D3DAPPLICATION3D_CONSTRUCTOR(_3D���ø����̼�);
protected:
	void OnInit() override;
	void OnUpdate() override;
	void OnRender() override;
	void OnRelease() override;
};

