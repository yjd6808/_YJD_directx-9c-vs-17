#include "D3DScale.h"

D3DScale::D3DScale() :
	x(1.0f),
	y(1.0f),
	z(1.0f)
{
}

D3DScale::D3DScale(float x, float y) :
	x(x),
	y(y),
	z(1.0f)
{
}

D3DScale::D3DScale(float x, float y, float z) :
	x(x),
	y(y),
	z(z)
{
}

D3DScale::D3DScale(const D3DScale & point) :
	x(point.x),
	y(point.y),
	z(point.z)
{
}

D3DScale::~D3DScale()
{
}

D3DScale & D3DScale::operator*=(const float data)
{
	this->x *= data;
	this->y *= data;
	this->z *= data;
	return *this;
}

D3DScale & D3DScale::operator/=(const float data)
{
	this->x /= data;
	this->y /= data;
	this->z /= data;
	return *this;
}

D3DScale & D3DScale::operator-=(const float data)
{
	this->x -= data;
	this->y -= data;
	this->z -= data;
	return *this;
}

D3DScale & D3DScale::operator+=(const float data)
{
	this->x += data;
	this->y += data;
	this->z += data;
	return *this;
}

D3DScale & D3DScale::operator+=(const D3DScale & point)
{
	this->x += point.x;
	this->y += point.y;
	this->z += point.z;
	return *this;
}

D3DScale & D3DScale::operator-=(const D3DScale & point)
{
	this->x -= point.x;
	this->y -= point.y;
	this->z -= point.z;
	return *this;
}

D3DScale & D3DScale::operator=(const D3DScale & point)
{
	this->x = point.x;
	this->y = point.y;
	this->z = point.z;
	return *this;
}
