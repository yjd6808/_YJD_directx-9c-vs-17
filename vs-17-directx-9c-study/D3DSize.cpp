#include "D3DSize.h"

D3DSize::D3DSize() :
	width(0.0f),
	height(0.0f)
{
}

D3DSize::D3DSize(float width, float height) :
	width(width),
	height(height)
{
}

D3DSize::D3DSize(const D3DSize & size) :
	width(size.width),
	height(size.height)
{
}

D3DSize::~D3DSize()
{
}

D3DSize & D3DSize::operator*=(const float data)
{
	this->width *= data;
	this->height *= data;
	return *this;
}

D3DSize & D3DSize::operator/=(const float data)
{
	this->width /= data;
	this->height /= data;
	return *this;
}

D3DSize & D3DSize::operator-=(const float data)
{
	this->width -= data;
	this->height -= data;
	return *this;
}

D3DSize & D3DSize::operator+=(const float data)
{
	this->width += data;
	this->height += data;
	return *this;
}

D3DSize & D3DSize::operator+=(const D3DSize & size)
{
	this->width += size.width;
	this->height += size.height;
	return *this;
}

D3DSize & D3DSize::operator-=(const D3DSize & size)
{
	this->width -= size.width;
	this->height -= size.height;
	return *this;
}

D3DSize & D3DSize::operator=(const D3DSize & size)
{
	this->width = size.width;
	this->height = size.height;
	return *this;
}