#include "D3DRotation.h"

D3DRotation::D3DRotation() :
	x(0.0f),
	y(0.0f),
	z(0.0f)
{
}

D3DRotation::D3DRotation(float x, float y) :
	x(x),
	y(y),
	z(0.0f)
{
}

D3DRotation::D3DRotation(float x, float y, float z) :
	x(x),
	y(y),
	z(z)
{
}

D3DRotation::D3DRotation(const D3DRotation & point) :
	x(point.x),
	y(point.y),
	z(point.z)
{
}

D3DRotation::~D3DRotation()
{
}

D3DRotation & D3DRotation::operator*=(const float data)
{
	this->x *= data;
	this->y *= data;
	this->z *= data;
	return *this;
}

D3DRotation & D3DRotation::operator/=(const float data)
{
	this->x /= data;
	this->y /= data;
	this->z /= data;
	return *this;
}

D3DRotation & D3DRotation::operator-=(const float data)
{
	this->x -= data;
	this->y -= data;
	this->z -= data;
	return *this;
}

D3DRotation & D3DRotation::operator+=(const float data)
{
	this->x += data;
	this->y += data;
	this->z += data;
	return *this;
}

D3DRotation & D3DRotation::operator+=(const D3DRotation & point)
{
	this->x += point.x;
	this->y += point.y;
	this->z += point.z;
	return *this;
}

D3DRotation & D3DRotation::operator-=(const D3DRotation & point)
{
	this->x -= point.x;
	this->y -= point.y;
	this->z -= point.z;
	return *this;
}

D3DRotation & D3DRotation::operator=(const D3DRotation & point)
{
	this->x = point.x;
	this->y = point.y;
	this->z = point.z;
	return *this;
}
