#pragma once

class D3DSize
{
public:
	float width;
	float height;

	D3DSize();
	D3DSize(float width, float height);
	D3DSize(const D3DSize& size);
	~D3DSize();

	D3DSize& operator*=(const float data);
	D3DSize& operator/=(const float data);
	D3DSize& operator-=(const float data);
	D3DSize& operator+=(const float data);

	D3DSize& operator+=(const D3DSize& size);
	D3DSize& operator-=(const D3DSize& size);
	D3DSize& operator=(const D3DSize& size);
};