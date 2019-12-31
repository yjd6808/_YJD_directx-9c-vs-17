#pragma once

#include "D3DApplication.h"
#include <d3d9.h>
#include "D3DMacro.h"

class D3DApplication2D : public D3DApplication
{
	CREATE_D3DAPPLICATION_CONSTRUCTOR(D3DApplication2D);
protected:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDevice;
protected:
	bool Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
protected:
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnRelease() = 0;
protected:
};