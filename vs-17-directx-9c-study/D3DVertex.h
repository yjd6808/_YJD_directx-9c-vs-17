#pragma once

#include "D3DPoint.h"

typedef struct 
{
	D3DPoint3D point;
	unsigned color;
} D3DVertex3D;

typedef struct
{
	D3DPoint3D point;
	float tu, tv;
} D3DVertex3DTexture;

typedef struct 
{
	D3DPoint3D point; 
	float rhw;
	unsigned color;
} D3DVertex2D;

#define D3DFVF2D (0x004 | 0x040) // = ( D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
#define D3DFVF3D (0x002 | 0x040) // = ( D3DFVF_XYZ | D3DFVF_DIFFUSE)
#define D3DFVF3DTEX (0x002 | 0x100) // = ( D3DFVF_XYZ | D3DFVF_TEX1)
