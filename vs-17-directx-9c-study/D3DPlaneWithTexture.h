/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-17 오전 11:53:25
 * Description : 텍스쳐를 입힌 사각형
 */


#pragma once

#include <vector>

#include "D3DVertex.h"
#include "D3DObject.h"
#include "D3DMacro.h"

class D3DPlaneWithTexture : public D3DObject
{
	CREATE_D3DOBJECT_CONSTRUCTOR_WITH_2PARAM(D3DPlaneWithTexture, int, length, m_length, std::string, name, m_textureFile);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DPlaneWithTexture);
private:
	std::vector<D3DVertex3DTexture> m_vertexes;
	int m_indicSize;

	LPDIRECT3DVERTEXBUFFER9  m_pVertextBuffer;
	LPDIRECT3DINDEXBUFFER9 m_pIndexBuffer;
	LPDIRECT3DTEXTURE9 m_pTexture;
protected:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();
};