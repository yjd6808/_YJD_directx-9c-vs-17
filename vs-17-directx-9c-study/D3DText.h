#pragma once

#include "D3DObject.h"
#include "D3DMacro.h"
#include "D3DColor.h"

#include <d3dx9.h>
#include <string>

class D3DText : public D3DObject
{
	CREATE_D3DOBJECT_CONSTRUCTOR_WITH_1PARAM(D3DText, std::string, text, m_text);
	CREATE_D3DOBJECT_DESTRUCTOR(D3DText);
public:
	enum class ThinType 
	{
		THIN		= 100,
		EXTRALIGHT	= 200,
		LIGHT		= 300,
		NORMAL		= 400,
		MEDIUM		= 500,
		SEMIBOLD	= 600,
		BOLD		= 700,
		EXTRABOLD	= 800,
		HEAVY		= 900
	};
private:
	LPD3DXSPRITE m_fontSprite;
	LPD3DXFONT m_font;
	ThinType m_thinType;
	D3DColor m_color;
	bool m_isItalic;
	unsigned m_fontSize;
public:
	void SetItalic(bool useItalic);
	void SetThinType(ThinType thinType);
	void SetText(std::string text);
	void SetColor(D3DColor color);
	void SetFontSize(unsigned size);
private:
	void UpdateFont();
protected:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();
};
