#pragma once

#include "D3DPoint.h"

typedef struct 
{
	D3DPoint3D point;
	u_int color;
} D3DVertex3D;

typedef struct 
{
	D3DPoint3D point; 
	float rhw;
	u_int color;
} D3DVertex2D;

#define D3DFVF2D (0x004 | 0x040) // = ( D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
#define D3DFVF3D (0x002 | 0x040) // = ( D3DFVF_XYZ | D3DFVF_DIFFUSE)
