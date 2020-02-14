#pragma once

#include "D3DApplication.h"
#include <d3d9.h>
#include "D3DMacro.h"
#include "D3DCamera.h"
#include "D3DObjectFactory.h"

class D3DApplication3D : public D3DApplication
{
	CREATE_D3DAPPLICATION_CONSTRUCTOR(D3DApplication3D);

public:
	LPDIRECT3DDEVICE9 GetDevice();

	virtual ~D3DApplication3D();
protected:
	bool Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
protected:
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
protected:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	D3DCamera* m_camera;
	D3DObjectFactory* m_objectFactory;
};