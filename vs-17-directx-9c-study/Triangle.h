/*
 *@Author		: JungDo Yun
 *@Created		: 2019-12-25 오후 10:22:30
 *@Description	: 삼각형 객체화
 */

#pragma once

#include <d3d9.h>

#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)

typedef struct
{
	FLOAT x, y, z;    // from the D3DFVF_XYZRHW flag
	DWORD color;			 // from the D3DFVF_DIFFUSE flag
}CUSTOMVERTEX;

using namespace std;

class Triangle {
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	LPDIRECT3DVERTEXBUFFER9 m_Vbuffer;
public:
	void OnInit(LPDIRECT3DDEVICE9 d3dDevice);
	void OnRender();
	void OnRelease();
};