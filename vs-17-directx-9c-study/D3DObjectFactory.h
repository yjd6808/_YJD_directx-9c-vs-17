#pragma once

#include <d3d9.h>
#include "D3DCamera.h"
#include "D3DCube.h"

class D3DObjectFactory {
public:
	D3DObjectFactory(LPDIRECT3DDEVICE9 d3dDev);

	
	D3DCamera* CreateCamera();
	D3DCube* CreateCube(float length);
	/*T CreateRectangleBox(float x_length, float y_length, float z_length);
	T CreateSphere(float radious);*/

private:
	LPDIRECT3DDEVICE9 m_pD3DDevice;
};

