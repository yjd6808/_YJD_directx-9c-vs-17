#pragma once

#include "D3DApplication3D.h"

#include "D3DCube.h"
#include <vector>

class _3D���ø����̼� : public D3DApplication3D
{
	CREATE_D3DAPPLICATION3D_CONSTRUCTOR(_3D���ø����̼�);
protected:
	void OnInit() override;
	void OnUpdate() override;
private:
	D3DCube* cube;
	D3DObject* obj;
	std::vector<D3DKeyboardEvent::KeyCode> m_keyCodeVec;
};

