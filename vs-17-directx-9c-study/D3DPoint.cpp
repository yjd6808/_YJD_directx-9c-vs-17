#include "D3DPoint.h"

#include <math.h>

D3DPoint2D::D3DPoint2D() :
	x(0.0f),
	y(0.0f)
{
}

D3DPoint2D::D3DPoint2D(float x, float y) :
	x(x),
	y(y)
{
}

D3DPoint2D::D3DPoint2D(const D3DPoint2D & point) :
	x(point.x),
	y(point.y)
{
}

D3DPoint2D::~D3DPoint2D()
{
}

D3DPoint2D & D3DPoint2D::operator*=(const float data)
{
	this->x *= data;
	this->y *= data;
	return *this;
}

D3DPoint2D & D3DPoint2D::operator/=(const float data)
{
	this->x /= data;
	this->y /= data;
	return *this;
}

D3DPoint2D & D3DPoint2D::operator-=(const float data)
{
	this->x -= data;
	this->y -= data;
	return *this;
}

D3DPoint2D & D3DPoint2D::operator+=(const float data)
{
	this->x += data;
	this->y += data;
	return *this;
}

D3DPoint2D & D3DPoint2D::operator+=(const D3DPoint2D & point)
{
	this->x += point.x;
	this->y += point.y;
	return *this;
}

D3DPoint2D & D3DPoint2D::operator-=(const D3DPoint2D & point)
{
	this->x -= point.x;
	this->y -= point.y;
	return *this;
}

D3DPoint2D & D3DPoint2D::operator=(const D3DPoint2D & point)
{
	this->x = point.x;
	this->y = point.y;
	return *this;
}


/* ---------------------------------------------------------------  */

D3DPoint3D::D3DPoint3D() :
	x(0.0f),
	y(0.0f),
	z(0.0f)
{
}

D3DPoint3D::D3DPoint3D(float x, float y) :
	x(x),
	y(y),
	z(0.0f)
{
}

D3DPoint3D::D3DPoint3D(float x, float y, float z) :
	x(x),
	y(y),
	z(z)
{
}

D3DPoint3D::D3DPoint3D(const D3DPoint2D & point) :
	x(point.x),
	y(point.y),
	z(0.0f)
{
}

D3DPoint3D::D3DPoint3D(const D3DPoint3D & point) :
	x(point.x),
	y(point.y),
	z(point.z)
{
}

D3DPoint3D::~D3DPoint3D()
{
}

D3DPoint3D & D3DPoint3D::operator*=(const float data)
{
	this->x *= data;
	this->y *= data;
	this->z *= data;
	return *this;
}

D3DPoint3D & D3DPoint3D::operator/=(const float data)
{
	this->x /= data;
	this->y /= data;
	this->z /= data;
	return *this;
}

D3DPoint3D & D3DPoint3D::operator-=(const float data)
{
	this->x -= data;
	this->y -= data;
	this->z -= data;
	return *this;
}

D3DPoint3D & D3DPoint3D::operator+=(const float data)
{
	this->x += data;
	this->y += data;
	this->z += data;
	return *this;
}

D3DPoint3D & D3DPoint3D::operator+=(const D3DPoint3D & point)
{
	this->x += point.x;
	this->y += point.y;
	this->z += point.z;
	return *this;
}

D3DPoint3D & D3DPoint3D::operator-=(const D3DPoint3D & point)
{
	this->x -= point.x;
	this->y -= point.y;
	this->z -= point.z;
	return *this;
}

D3DPoint3D & D3DPoint3D::operator=(const D3DPoint3D & point)
{
	this->x = point.x;
	this->y = point.y;
	this->z = point.z;
	return *this;
}

float D3DPoint3D::DistanceTo(const D3DPoint3D & point)
{
	return sqrtf(powf(this->x, 2.0f) + powf(this->x, 2.0f) + powf(this->x, 2.0f));
}
