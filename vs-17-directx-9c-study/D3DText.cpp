/*
 * @Author	: Jungdo Yun
 * @Created	: 19.12.??
 */

#include "D3DText.h"

void D3DText::OnInit()
{
	//���� �ʱ�ȭ
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
		m_fontSize * 72 / 96,				//������ �ȼ� ����
		0,									//������ �ȼ� �� (0�� ����ϸ� �۲� ũ�⿡ ���� Height �Ű� ������ ���������� ������ �� �ְ� �������)
		static_cast<int>(m_thinType),		//���� Ÿ��
		1,									//Miplevel : �׻� 1�μ����Ѵ�.
		m_isItalic,							//��Ż��ü ��뿩��
		DEFAULT_CHARSET,					//CharSet : �׻� DEFAULT_CHARSET�� ����ϴµ�, ���� �ý��� ������ ����� �ΰ� ���� ������ �����Ѵ� ��� ������ �ٸ� ���� ������ ����
											//o ANSI_CHARSET : ��� ��� ������ �ý��ۿ����� DEFAULT_CHARSET�� ����
											//o SYMBOL_CHARSET : �ɺ� ������ �����Ѵ�
											//o MAC_CHARSET : ���� ��Ų��� ���� ������ �����Ѵ�
		OUT_DEFAULT_PRECIS,                 //OutputPrecision : Windows�� ���ϴ� �۲��� ���� �۲ð� ��ġ��Ű�� ����� �����Ѵ�.
											//�׻� Ʈ��Ÿ�� �۲��� �������� OUT_TT_ONLY_PRECIS�� ����Ѵ�.
		DEFAULT_QUALITY,					//Quality : Windows�� ���ϴ� �۲��� ���� �۲ð� ��ġ��Ű�� ����� �����Ѵ�. 
											//������ �۲ÿ��� ����ǰ� Ʈ��Ÿ�� �۲ÿ��� ������ ��ġ�� �ʴ´�.
		DEFAULT_PITCH | FF_DONTCARE,			//���� �� �̷����
		"Arial",
		&m_font);

}
