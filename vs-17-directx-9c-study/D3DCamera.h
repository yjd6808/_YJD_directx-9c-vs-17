#pragma once

#include "D3DObject.h"
#include "D3DMacro.h"
#include <d3dx9.h>

class D3DCamera : public D3DObject
{
	CREATE_D3DOBJECT_CONSTRUCTOR(D3DCamera);
	CREATE_D3DOBJECT_CONSTRUCTOR_WITH_1PARAM(D3DCamera, HWND, hwnd, m_hWnd);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DCamera);
private:
	void SetView();
	void SetViewport();
	void SetProjection();
	void Initialize();
public:
	void SetLookAt(D3DPoint3D lookAt);
	void SetLookAtX(float lookAt_x);
	void SetLookAtY(float lookAt_y);
	void SetLookAtZ(float lookAt_z);

	D3DPoint3D GetLookAt();
	float GetLookAtX();
	float GetLookAtY();
	float GetLookAtZ();
protected:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease() {};
protected:
	D3DVIEWPORT9 m_viewPort;
	D3DPoint3D m_lookAt;		//ī�޶� ���¹���
	D3DPoint3D m_lookUp;		//���� ��
	D3DXMATRIXA16 m_viewMat;	//position, lookat, axis�� ������ ���յ� �� ���
	D3DXMATRIXA16 m_projMat;	//�������
	//ȭ��� �����Ǵ� ������ ��Ÿ��
	float m_viewDegree;		// �þ߰�


	DWORD m_dwElapsedTime;
	RECT rect;
	POINT centerPt;
	bool isClip;

	friend class D3DApplication3D;
};