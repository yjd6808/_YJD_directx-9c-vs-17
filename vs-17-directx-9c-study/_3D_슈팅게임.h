/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-18 오후 3:03:00
 * Description : 
 */

#include "D3DApplication3D.h"

#include "D3DCube.h"
#include "D3DMeshCube.h"
#include "D3DSphere.h"
#include "D3DPlane.h"
#include <vector>

#pragma once

class _3D_슈팅게임 : public D3DApplication3D
{
	CREATE_D3DAPPLICATION3D_CONSTRUCTOR(_3D_슈팅게임);
protected:
	void OnInit() override;
	void OnUpdate() override;
	void OnInitEnd() override;
private:


	std::vector<D3DKeyboardEvent::KeyCode> m_keyCodeVec;
	inline const std::string GetApplicationName() override { return "3D 슈팅게임"; }
};
