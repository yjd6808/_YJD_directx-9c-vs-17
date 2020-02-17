#pragma once

#include "D3DCamera.h"
#include "D3DCube.h"
#include "D3DAxis.h"
#include "D3DPlane.h"
#include "D3DText.h"
#include "D3DPlaneWithTexture.h"
#include "D3DMeshCube.h"
#include "D3DSphere.h"

#include <d3d9.h>


class D3DObjectFactory {
public:
	D3DObjectFactory(LPDIRECT3DDEVICE9 d3dDev);

	
	D3DCamera* CreateCamera(HWND hwnd);
	D3DCube* CreateCube(float length);
	D3DMeshCube* CreateMeshCube(float length);
	D3DAxis* CreateAxis(float length);
	D3DPlane* CreatePlane(int width, int height, float squreSideLength);
	D3DText* CreateText(std::string text);
	D3DSphere* CreateSphere(float radious);
	D3DPlaneWithTexture* CreatePlaneWithTexture(int length, std::string TextureFileName);

private:
	LPDIRECT3DDEVICE9 m_pD3DDevice;
};

