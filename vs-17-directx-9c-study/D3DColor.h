#pragma once

#include "D3DMacro.h"

class D3DColor 
{
public:
	static const D3DColor WHITE;
	static const D3DColor BLACK;
	static const D3DColor RED;
	static const D3DColor GREEN;
	static const D3DColor YELLOW;
	static const D3DColor VIOLET;
	static const D3DColor BLUE;
	static const D3DColor CYAN;

	enum class Color : unsigned
	{
		WHITE		= D3DCOLOR_WHITE,
		BLACK		= D3DCOLOR_BLACK,
		RED			= D3DCOLOR_RED,
		GREEN		= D3DCOLOR_GREEN,
		YELLOW		= D3DCOLOR_YELLOW,
		VIOLET		= D3DCOLOR_VIOLET,
		BLUE		= D3DCOLOR_BLUE,
		CYAN		= D3DCOLOR_CYAN
	};

	
	union {
		struct {
			unsigned char a;
			unsigned char r;
			unsigned char g;
			unsigned char b;
		};
		unsigned value;
	};
public:
	D3DColor();
	D3DColor(const unsigned colorValue);
	D3DColor(const Color color);
	D3DColor(const unsigned char a, const unsigned char r, const unsigned char g, const unsigned char b);
	~D3DColor() {}
};

