#pragma once

#define CREATE_D3DAPPLICATION_CONSTRUCTOR(className) public: \
className(HINSTANCE hInstance, \
HINSTANCE hPrevInstance, \
LPWSTR    lpCmdLine, \
int       nCmdShow) : D3DApplication(hInstance, hPrevInstance, lpCmdLine, nCmdShow) {}

#define CREATE_D3DAPPLICATION2D_CONSTRUCTOR(className) public: \
className(HINSTANCE hInstance, \
HINSTANCE hPrevInstance, \
LPWSTR    lpCmdLine, \
int       nCmdShow) : D3DApplication2D(hInstance, hPrevInstance, lpCmdLine, nCmdShow) {}

#define CREATE_D3DAPPLICATION3D_CONSTRUCTOR(className) public: \
className(HINSTANCE hInstance, \
HINSTANCE hPrevInstance, \
LPWSTR    lpCmdLine, \
int       nCmdShow) : D3DApplication3D(hInstance, hPrevInstance, lpCmdLine, nCmdShow) {}

#define CREATE_D3DOBJECT_CONSTRUCTOR(className) public: \
className(LPDIRECT3DDEVICE9 d3dDev) : D3DObject(d3dDev) {} 

#define CREATE_D3DOBJECT_CONSTRUCTOR_WITH_1PARAM(className, ptype, pname, vname) private: \
ptype vname;\
public: \
className(LPDIRECT3DDEVICE9 d3dDev, ptype pname) : D3DObject(d3dDev), vname(pname) {} 

#define CREATE_D3DOBJECT_CONSTRUCTOR_WITH_2PARAM(className, \
ptype_1, pname_1, vname_1, \
ptype_2, pname_2, vname_2) private: \
ptype_1 vname_1;\
ptype_2 pname_2;\
public: \
className(LPDIRECT3DDEVICE9 d3dDev, \
ptype_1, pname_1, \
ptype_2, pname_2) : D3DObject(d3dDev), \
vname_1(pname_1), \
vname_2(pname_2) {}

#define CREATE_D3DOBJECT_DESTRUCTOR(className) public: \
~className() {} 

//ÀÌ·± ÇÔ¼ö ÀÖÀ»°Å°°Àºµ¥ °Á Ã£¾Æº¸±â ±ÍÂú¾Æ¼­ ¸¸µë
#define D3DCOLOR_GETA(color) color >> 24
#define D3DCOLOR_GETR(color) color << 8 >> 24
#define D3DCOLOR_GETG(color) color << 16 >> 24
#define D3DCOLOR_GETB(color) color << 24 >> 24

#define D3DCOLOR_WHITE	0xffffffff
#define D3DCOLOR_BLACK	0xff000000
#define D3DCOLOR_RED	0xffff0000
#define D3DCOLOR_GREEN	0xff00ff00
#define D3DCOLOR_BLUE	0xff0000ff
