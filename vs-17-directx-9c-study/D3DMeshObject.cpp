#include "D3DMeshObject.h"

D3DMeshObject::D3DMeshObject(LPDIRECT3DDEVICE9 d3dDev) : D3DObject(d3dDev)
{
	m_diffuse.r = 1.0f;
	m_diffuse.g = 1.0f;
	m_diffuse.b = 1.0f;
	m_diffuse.a = 1.0f;

	m_ambient.r = 0.0f;
	m_ambient.g = 0.0f;
	m_ambient.b = 0.0f;
	m_ambient.a = 0.0f;

	m_specular.r = 0.0f;
	m_specular.g = 0.0f;
	m_specular.b = 0.0f;
	m_specular.a = 0.0f;
}

void D3DMeshObject::InitMaterial()
{
	ZeroMemory(&m_material, sizeof(D3DMATERIAL9));

	// Set the material's main color to green.
	m_material.Diffuse.r = m_diffuse.r;
	m_material.Diffuse.g = m_diffuse.g;
	m_material.Diffuse.b = m_diffuse.b;
	m_material.Diffuse.a = m_diffuse.a;

	// Lets favor the ambient's green over the other colors. Why? I don't know.
	// It just looks better to me. Using materials is some what more artistic
	// than scientific, so just play around till you get what you want.
	m_material.Ambient.r = m_ambient.r;
	m_material.Ambient.g = m_ambient.g;
	m_material.Ambient.b = m_ambient.b;
	m_material.Ambient.a = m_ambient.a;

	// Plastic can be shiny, but we don't want it too shiny are it will look 
	// more like glass or metal. We'll have the material reflect back more 
	// green than red and blue so the highlights won't be pure white.
	m_material.Specular.r = m_specular.r;
	m_material.Specular.g = m_specular.g;
	m_material.Specular.b = m_specular.b;
	m_material.Specular.a = m_specular.a;
}

void D3DMeshObject::OnInit()
{
	D3DObject::OnInit();
	InitMaterial();
}

void D3DMeshObject::OnRender()
{
	D3DObject::OnRender();
	m_pD3DDevice->SetMaterial(&m_material);
}

void D3DMeshObject::SetMaterialDiffuse(D3DCOLORVALUE color)
{
	m_diffuse = color;
	InitMaterial();
}

void D3DMeshObject::SetMaterialAmbient(D3DCOLORVALUE color)
{
	m_ambient = color;
	InitMaterial();
}

void D3DMeshObject::SetMaterialSpecular(D3DCOLORVALUE color)
{
	m_specular = color;
	InitMaterial();
}
