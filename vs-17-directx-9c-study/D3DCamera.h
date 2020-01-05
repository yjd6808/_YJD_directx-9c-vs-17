#pragma once

#include "D3DObject.h"
#include "D3DMacro.h"
#include <d3dx9.h>

class D3DCamera : public D3DObject
{
	CREATE_D3DOBJECT_CONSTRUCTOR(D3DCamera);
	CREATE_D3DOBJECT_CONSTRUCTOR_WITH_1PARAM(D3DCamera, HWND, hwnd, m_hWnd);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DCamera);

	void SetView();
	void SetViewport();
	void SetProjection();
protected:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();
public:
	virtual void SetPosition(const D3DPoint3D& point);
	virtual void SetPosition(const float x, const float y, const float z);
protected:
	D3DPoint3D m_lookAt;		//카메라가 보는방향
	D3DPoint3D m_stdAxis;		//기준 축
	D3DXMATRIXA16 m_viewMat;	//position, lookat, axis의 정보가 결합된 뷰 행렬
	D3DXMATRIXA16 m_projMat;	//투영행렬
	//화면상에 투영되는 정보가 나타남
	float m_viewDegree;		// 시야각

	friend class D3DApplication3D;
};