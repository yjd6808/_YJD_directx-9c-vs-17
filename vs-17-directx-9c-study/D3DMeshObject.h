/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-20 오전 11:03:26
 */

#pragma once

#include "D3DObject.h"
#include "D3DColor.h"

class D3DMeshObject : public D3DObject
{
public:
	D3DMeshObject(LPDIRECT3DDEVICE9 d3dDev);
	virtual ~D3DMeshObject() {}
private:
	void InitMaterial();
protected:
	virtual void OnInit();
	virtual void OnRender();
protected:
	D3DMATERIAL9 m_material;

	D3DCOLORVALUE m_diffuse;
	D3DCOLORVALUE m_ambient;
	D3DCOLORVALUE m_specular;
public:
	void SetMaterialDiffuse(D3DCOLORVALUE color);
	void SetMaterialAmbient(D3DCOLORVALUE color);
	void SetMaterialSpecular(D3DCOLORVALUE color);
};

