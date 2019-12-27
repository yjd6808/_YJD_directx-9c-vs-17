#pragma once
#include "D3DApp.h"


#include <d3d9.h>
#include "Triangle.h"





class D3DEdu01 : public D3DApp
{
	Triangle triangle;
public:
	virtual void OnUpdate();
	virtual void OnRelease();
	virtual void OnRender();
	virtual void OnInit();
public:
	D3DEdu01();
	~D3DEdu01();
};
