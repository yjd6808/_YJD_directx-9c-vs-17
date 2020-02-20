/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-20 오전 10:51:10
 * Description : MeshObject와 구분하기 위해 만들었다.
 */

#pragma once

#include "D3DObject.h"
#include "D3DMacro.h"



class D3DVertexObject : public D3DObject
{
public:
	D3DVertexObject(LPDIRECT3DDEVICE9 d3dDev) : D3DObject(d3dDev) { m_vertexColor = D3DCOLOR_WHITE; }
	virtual ~D3DVertexObject() {}
protected:
	DWORD m_vertexColor;
	virtual void ChangeVertexesColor();
public:
	void SetVertexColor(DWORD color);
};

