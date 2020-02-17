#pragma once

#include <d3d9.h>

#include "D3DPoint.h"
#include "D3DRotation.h"
#include "D3DScale.h"

class D3DObject
{
public:
	D3DObject(LPDIRECT3DDEVICE9 d3dDev);
	~D3DObject();
protected:
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnRelease() = 0;
public:
	void SetPosition(const D3DPoint3D& point);
	void SetPosition(const float x, const float y, const float z);
	void SetPositionX(const float x);
	void SetPositionY(const float y);
	void SetPositionZ(const float z);


	void SetRotation(const D3DRotation& rotation);
	void SetRotation(const float x, const float y, const float z);
	void SetRotationX(const float x);
	void SetRotationY(const float y);
	void SetRotationZ(const float z);

	void SetScale(const D3DScale& scale);
	void SetScale(const float x, const float y, const float z);
	void SetScaleX(const float scale_x);
	void SetScaleY(const float scale_y);
	void SetScaleZ(const float scale_z);

	D3DPoint3D GetPosition() const;
	float GetPositionX() const;
	float GetPositionY() const;
	float GetPositionZ() const;

	D3DRotation GetRotation() const;
	float GetRotationX() const;
	float GetRotationY() const;
	float GetRotationZ() const;

	D3DScale GetScale() const;
	float GetScaleX() const;
	float GetScaleY() const;
	float GetScaleZ() const;

	float DistanceFrom(D3DObject* obj) const;
protected:
	D3DPoint3D m_position;
	D3DRotation m_rotation;
	D3DScale m_scale;
	LPDIRECT3DDEVICE9 m_pD3DDevice;


	friend class D3DApplication3D;
	friend class D3DApplication2D;
};
