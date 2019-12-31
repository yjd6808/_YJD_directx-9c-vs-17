#pragma once

#include "D3DPoint.h"
#include <d3d9.h>



class D3DObject
{
public:
	D3DObject(LPDIRECT3DDEVICE9 d3dDev);
	~D3DObject();
public:
	virtual void SetPosition(const D3DPoint3D& point);
	virtual void SetPosition(const float x, const float y, const float z);

	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnRelease() = 0;

	D3DPoint3D& GetPosition();
protected:
	D3DPoint3D m_position;
	LPDIRECT3DDEVICE9 m_pD3DDevice;
};
