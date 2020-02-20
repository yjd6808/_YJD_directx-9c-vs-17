/*
 * @Author	: Jungdo Yun
 * @Created	: 19.12.??
 */

#pragma once

#include <d3d9.h>
#include <vector>

#include "D3DPoint.h"
#include "D3DRotation.h"
#include "D3DScale.h"
#include "D3DVertex.h"

class D3DObject
{
public:
	D3DObject(LPDIRECT3DDEVICE9 d3dDev);
	virtual ~D3DObject();
private:
	void InitSphereCollider();
	void InitHyperRectangleCollider();

	void RenderSphereCollider();
	void RenderHyperRectangleCollider();
protected:
	virtual void OnInit();
	virtual void OnUpdate() = 0;
	virtual void OnRender();
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

	void SetSolid(bool solidStatus);
	void SetLighting(bool lightingStatus);
	void SetSphereCollider(float length, bool use = true);
	void SetHyperRectangleCollider(float length, float depth, float height, bool use = true);
	void SetViewCollider(bool viewCollider);
	bool IsCollided(D3DObject* otherObject);
private:
	float m_sphereColliderLength;

	float m_hyperRectangleColliderLength;
	float m_hyperRectangleColliderDepth;
	float m_hyperRectangleColliderHeight;

	bool m_viewCollider;

	bool m_sphereColliderSetup;
	bool m_hyperRectangleColliderSetup;

	LPD3DXMESH m_sphereMesh;
	std::vector<D3DVertex3D>	m_hyperRectangleVertexes;
	LPDIRECT3DVERTEXBUFFER9		m_phyperRectangleVertextBuffer;
	LPDIRECT3DINDEXBUFFER9		m_phyperRectangleIndexBuffer;

	D3DPoint3D					m_hyperRectangleMin;
	D3DPoint3D					m_hyperRectangleMax;

	bool m_IsSolid;
	bool m_useLight;
protected:
	D3DPoint3D m_position;
	D3DRotation m_rotation;
	D3DScale m_scale;
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	

	friend class D3DApplication3D;
	friend class D3DApplication2D;
};
