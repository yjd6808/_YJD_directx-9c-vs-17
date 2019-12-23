#pragma once
#include "D3DApp.h"

class D3DEdu01 : public D3DApp
{
public:
	virtual void OnUpdate();
	virtual void OnRelease();
	virtual void OnRender();
	virtual void OnInit();

public:
	D3DEdu01();
	~D3DEdu01();
};
