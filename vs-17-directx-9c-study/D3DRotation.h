#pragma once

class D3DRotation
{
public:
	float x;
	float y;
	float z;

	D3DRotation();
	D3DRotation(float x, float y);
	D3DRotation(float x, float y, float z);
	D3DRotation(const D3DRotation& point);
	~D3DRotation();

	D3DRotation& operator*=(const float data);
	D3DRotation& operator/=(const float data);
	D3DRotation& operator-=(const float data);
	D3DRotation& operator+=(const float data);

	D3DRotation& operator+=(const D3DRotation& point);
	D3DRotation& operator-=(const D3DRotation& point);
	D3DRotation& operator=(const D3DRotation& point);
};