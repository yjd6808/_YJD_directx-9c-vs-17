#pragma once

class D3DScale
{
public:
	float x;
	float y;
	float z;

	D3DScale();
	D3DScale(float x, float y);
	D3DScale(float x, float y, float z);
	D3DScale(const D3DScale& point);
	~D3DScale();

	D3DScale& operator*=(const float data);
	D3DScale& operator/=(const float data);
	D3DScale& operator-=(const float data);
	D3DScale& operator+=(const float data);

	D3DScale& operator+=(const D3DScale& point);
	D3DScale& operator-=(const D3DScale& point);
	D3DScale& operator=(const D3DScale& point);
};