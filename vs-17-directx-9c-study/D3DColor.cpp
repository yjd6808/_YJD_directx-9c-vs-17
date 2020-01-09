#include "D3DColor.h"

const D3DColor D3DColor::WHITE		= D3DColor(D3DColor::Color::WHITE);
const D3DColor D3DColor::BLACK		= D3DColor(D3DColor::Color::BLACK);
const D3DColor D3DColor::RED		= D3DColor(D3DColor::Color::RED);
const D3DColor D3DColor::GREEN		= D3DColor(D3DColor::Color::GREEN);
const D3DColor D3DColor::YELLOW		= D3DColor(D3DColor::Color::YELLOW);
const D3DColor D3DColor::VIOLET		= D3DColor(D3DColor::Color::VIOLET);
const D3DColor D3DColor::BLUE		= D3DColor(D3DColor::Color::BLUE);
const D3DColor D3DColor::CYAN		= D3DColor(D3DColor::Color::CYAN);

D3DColor::D3DColor()
{
	value = static_cast<unsigned>(Color::WHITE);
}

D3DColor::D3DColor(const unsigned colorValue)
{
	value = colorValue;
}

D3DColor::D3DColor(const Color color)
{
	value = static_cast<unsigned>(color);
}

D3DColor::D3DColor(const unsigned char a, const unsigned char r, const unsigned char g, const unsigned char b)
{
	this->a = a;
	this->r = r;
	this->g = g;
	this->b = b;
}
