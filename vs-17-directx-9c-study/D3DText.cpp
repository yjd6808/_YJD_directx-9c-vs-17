/*
 * @Author	: Jungdo Yun
 * @Created	: 19.12.??
 */

#include "D3DText.h"

void D3DText::OnInit()
{
	//변수 초기화
	m_thinType = ThinType::NORMAL;
	m_isItalic = false;

	D3DXCreateSprite(m_pD3DDevice, &m_fontSprite);
	UpdateFont();
}

void D3DText::OnUpdate()
{
}

void D3DText::OnRender()
{
	RECT rect;
	SetRect(&rect, 0, 0, 0, 0);
	
	D3DXMATRIX scaleMat;
	D3DXMatrixScaling(&scaleMat, m_scale.x, m_scale.y, m_scale.z);

	D3DXMATRIX rotMat;
	D3DXMatrixRotationYawPitchRoll(&rotMat, m_rotation.y * 3.141592 / 180.0f, m_rotation.x * 3.141592 / 180.0f, m_rotation.z * 3.141592 / 180.0f);

	D3DXMATRIX translationMat;
	D3DXMatrixTranslation(&translationMat, m_position.x, m_position.y, m_position.z);

	D3DXMATRIX transformResult = scaleMat * rotMat * translationMat;
	m_fontSprite->SetTransform(&transformResult);
	m_fontSprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_font->DrawText(m_fontSprite, m_text.c_str(), -1, &rect, DT_NOCLIP, m_color.value);
	m_fontSprite->End();
}

void D3DText::OnRelease()
{
	if (m_fontSprite != nullptr)
		m_fontSprite->Release();

	if (m_font != nullptr)
		m_font->Release();
}

void D3DText::SetItalic(bool useItalic)
{
	m_isItalic = useItalic;
	UpdateFont();
}

void D3DText::SetThinType(ThinType thinType)
{
	m_thinType = thinType;
	UpdateFont();
}

void D3DText::SetColor(D3DColor color)
{
	m_color = color;
}

void D3DText::SetFontSize(unsigned size)
{
	m_fontSize = size;
	UpdateFont();
}

void D3DText::SetText(std::string text)
{
	m_text = text;
	UpdateFont();
}

void D3DText::UpdateFont()
{
	D3DXCreateFont(
		m_pD3DDevice,
		m_fontSize * 72 / 96,				//문자의 픽셀 높이
		0,									//문자의 픽셀 폭 (0을 사용하면 글꼴 크기에 대해 Height 매개 변수를 독점적으로 제어할 수 있게 만들어줌)
		static_cast<int>(m_thinType),		//굵기 타입
		1,									//Miplevel : 항상 1로설정한다.
		m_isItalic,							//이탈릭체 사용여부
		DEFAULT_CHARSET,					//CharSet : 항상 DEFAULT_CHARSET을 사용하는데, 현재 시스템 지역에 기반을 두고 문자 집합을 지정한다 사용 가능한 다른 값은 다음과 같다
											//o ANSI_CHARSET : 영어를 사용 지역의 시스템에서는 DEFAULT_CHARSET과 같다
											//o SYMBOL_CHARSET : 심볼 집합을 생성한다
											//o MAC_CHARSET : 애플 매킨토시 문자 집합을 생성한다
		OUT_DEFAULT_PRECIS,                 //OutputPrecision : Windows가 원하는 글꼴을 실제 글꼴과 일치시키는 방법을 지정한다.
											//항상 트루타입 글꼴을 얻으려면 OUT_TT_ONLY_PRECIS를 사용한다.
		DEFAULT_QUALITY,					//Quality : Windows가 원하는 글꼴을 실제 글꼴과 일치시키는 방법을 지정한다. 
											//레스터 글꼴에만 적용되고 트루타입 글꼴에는 영향을 미치지 않는다.
		DEFAULT_PITCH | FF_DONTCARE,			//몰라 걍 이래써라
		"Arial",
		&m_font);

}
