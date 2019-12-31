#pragma once

class D3DPoint2D
{
public:
	float x;
	float y;

	D3DPoint2D();
	D3DPoint2D(float x, float y);
	D3DPoint2D(const D3DPoint2D& point);
	~D3DPoint2D();

	D3DPoint2D& operator*=(const float data);
	D3DPoint2D& operator/=(const float data);
	D3DPoint2D& operator-=(const float data);
	D3DPoint2D& operator+=(const float data);

	D3DPoint2D& operator+=(const D3DPoint2D& point);
	D3DPoint2D& operator-=(const D3DPoint2D& point);
	D3DPoint2D& operator=(const D3DPoint2D& point);
};

class D3DPoint3D
{
public:
	float x;
	float y;
	float z;

	D3DPoint3D();
	D3DPoint3D(float x, float y);
	D3DPoint3D(float x, float y, float z);
	D3DPoint3D(const D3DPoint2D& point);
	D3DPoint3D(const D3DPoint3D& point);
	~D3DPoint3D();

	D3DPoint3D& operator*=(const float data);
	D3DPoint3D& operator/=(const float data);
	D3DPoint3D& operator-=(const float data);
	D3DPoint3D& operator+=(const float data);

	D3DPoint3D& operator+=(const D3DPoint3D& point);
	D3DPoint3D& operator-=(const D3DPoint3D& point);
	D3DPoint3D& operator=(const D3DPoint3D& point);
};