#pragma once

#include <d3d9.h>
#include "D3DCamera.h"
#include "D3DCube.h"
#include "D3DAxis.h"
#include "D3DPlane.h"

class D3DObjectFactory {
public:
	D3DObjectFactory(LPDIRECT3DDEVICE9 d3dDev);

	
	D3DCamera* CreateCamera(HWND hwnd);
	D3DCube* CreateCube(float length);
	D3DAxis* CreateAxis(float length);
	D3DPlane* CreatePlane(int width, int height, float squreSideLength);
	/*T CreateRectangleBox(float x_length, float y_length, float z_length);
	T CreateSphere(float radious);*/

private:
	LPDIRECT3DDEVICE9 m_pD3DDevice;
};

