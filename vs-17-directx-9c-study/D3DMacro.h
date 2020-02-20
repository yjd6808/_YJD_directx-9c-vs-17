/*
 * @Author	: Jungdo Yun
 * @Created	: 19.12.??
 */

#pragma once

/********************************************************************************
 *                                                                              *
 *                                                                              *
 *                                윈도우 매크로                                 *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/

#define WINDOW_X		300
#define WINDOW_Y		300
#define WINDOW_WIDTH	1280
#define WINDOW_HEIGHT	720


/********************************************************************************
 *                                                                              *
 *                                                                              *
 *                                함수 매크로                                   *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/

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

 /********************************************************************************
 *                                                                              *
 *                                                                              *
 *                            오브젝트 컨스트럭터                               *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/
#define CREATE_D3DOBJECT_CONSTRUCTOR(className) public: \
className(LPDIRECT3DDEVICE9 d3dDev) : D3DObject(d3dDev) {} 

#define CREATE_D3DOBJECT_CONSTRUCTOR_WITH_1PARAM(className, ptype, pname, vname) private: \
ptype vname;\
public: \
className(LPDIRECT3DDEVICE9 d3dDev, ptype pname) : D3DObject(d3dDev), vname(pname) {} 

#define CREATE_D3DOBJECT_CONSTRUCTOR_WITH_2PARAM(className, \
ptype_1, pname_1, vname_1, \
ptype_2, pname_2, vname_2) \
private: \
ptype_1 vname_1; \
ptype_2 vname_2; \
public: \
className(LPDIRECT3DDEVICE9 d3dDev, ptype_1 pname_1, ptype_2 pname_2) : D3DObject(d3dDev), \
vname_1(pname_1), \
vname_2(pname_2) {}

#define CREATE_D3DOBJECT_CONSTRUCTOR_WITH_3PARAM(className, \
ptype_1, pname_1, vname_1, \
ptype_2, pname_2, vname_2, \
ptype_3, pname_3, vname_3) \
private: \
ptype_1 vname_1; \
ptype_2 vname_2; \
ptype_3 vname_3; \
public: \
className(LPDIRECT3DDEVICE9 d3dDev, ptype_1 pname_1, ptype_2 pname_2, ptype_3 pname_3) : D3DObject(d3dDev), \
vname_1(pname_1), \
vname_2(pname_2), \
vname_3(pname_3) {}


#define CREATE_D3DOBJECT_DESTRUCTOR(className) public: \
~className() {} 

 /********************************************************************************
  *                                                                              *
  *                                                                              *
  *                         메쉬 오브젝트 컨스트럭터                             *
  *                                                                              *
  *                                                                              *
  ********************************************************************************/

#define CREATE_D3D_MESH_OBJECT_CONSTRUCTOR(className) public: \
className(LPDIRECT3DDEVICE9 d3dDev) : D3DMeshObject(d3dDev) {} 

#define CREATE_D3D_MESH_OBJECT_CONSTRUCTOR_WITH_1PARAM(className, ptype, pname, vname) private: \
ptype vname;\
public: \
className(LPDIRECT3DDEVICE9 d3dDev, ptype pname) : D3DMeshObject(d3dDev), vname(pname) {} 

#define CREATE_D3D_MESH_OBJECT_CONSTRUCTOR_WITH_2PARAM(className, \
ptype_1, pname_1, vname_1, \
ptype_2, pname_2, vname_2) \
private: \
ptype_1 vname_1; \
ptype_2 vname_2; \
public: \
className(LPDIRECT3DDEVICE9 d3dDev, ptype_1 pname_1, ptype_2 pname_2) : D3DMeshObject(d3dDev), \
vname_1(pname_1), \
vname_2(pname_2) {}

#define CREATE_D3D_MESH_OBJECT_CONSTRUCTOR_WITH_3PARAM(className, \
ptype_1, pname_1, vname_1, \
ptype_2, pname_2, vname_2, \
ptype_3, pname_3, vname_3) \
private: \
ptype_1 vname_1; \
ptype_2 vname_2; \
ptype_3 vname_3; \
public: \
className(LPDIRECT3DDEVICE9 d3dDev, ptype_1 pname_1, ptype_2 pname_2, ptype_3 pname_3) : D3DMeshObject(d3dDev), \
vname_1(pname_1), \
vname_2(pname_2), \
vname_3(pname_3) {}

 /********************************************************************************
 *                                                                              *
 *                                                                              *
 *                        버텍스 오브젝트 컨스트럭터                            *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/
#define CREATE_D3D_VERTEX_OBJECT_CONSTRUCTOR(className) public: \
className(LPDIRECT3DDEVICE9 d3dDev) : D3DVertexObject(d3dDev) {} 

#define CREATE_D3D_VERTEX_OBJECT_CONSTRUCTOR_WITH_1PARAM(className, ptype, pname, vname) private: \
ptype vname;\
public: \
className(LPDIRECT3DDEVICE9 d3dDev, ptype pname) : D3DVertexObject(d3dDev), vname(pname) {} 

#define CREATE_D3D_VERTEX_OBJECT_CONSTRUCTOR_WITH_2PARAM(className, \
ptype_1, pname_1, vname_1, \
ptype_2, pname_2, vname_2) \
private: \
ptype_1 vname_1; \
ptype_2 vname_2; \
public: \
className(LPDIRECT3DDEVICE9 d3dDev, ptype_1 pname_1, ptype_2 pname_2) : D3DVertexObject(d3dDev), \
vname_1(pname_1), \
vname_2(pname_2) {}

#define CREATE_D3D_VERTEX_OBJECT_CONSTRUCTOR_WITH_3PARAM(className, \
ptype_1, pname_1, vname_1, \
ptype_2, pname_2, vname_2, \
ptype_3, pname_3, vname_3) \
private: \
ptype_1 vname_1; \
ptype_2 vname_2; \
ptype_3 vname_3; \
public: \
className(LPDIRECT3DDEVICE9 d3dDev, ptype_1 pname_1, ptype_2 pname_2, ptype_3 pname_3) : D3DVertexObject(d3dDev), \
vname_1(pname_1), \
vname_2(pname_2), \
vname_3(pname_3) {}




 /********************************************************************************
 *                                                                              *
 *                                                                              *
 *                           버퍼 생성 및 복사                                  *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/

//dstD3DBuffer : 인덱스버퍼나 정점버퍼
//srcArray : 복사할 데이터
//일부러 중괄호를 줘서 내부에 지역변수를 만들어 중복된 이름을 방지함
#define D3DLOCKCOPY(dstD3DBuffer, srcArray)  { void* voidBuffer; \
dstD3DBuffer->Lock(0, sizeof(srcArray), &voidBuffer, 0); \
memcpy(voidBuffer, srcArray, sizeof(srcArray)); \
dstD3DBuffer->Unlock(); }

#define D3DLOCKCOPY_DYNAMIC(dstD3DBuffer, srcArray, srcArraySize)  { void* voidBuffer; \
dstD3DBuffer->Lock(0, srcArraySize, &voidBuffer, 0); \
memcpy(voidBuffer, srcArray, srcArraySize); \
dstD3DBuffer->Unlock(); }

#define D3DCREATE_VERTEXBUFFER(d3dDevice, vertexBuffer,  vertexArray) \
d3dDevice->CreateVertexBuffer( \
	sizeof(vertexArray), \
	0, \
	D3DFVF3D, \
	D3DPOOL_DEFAULT, \
	&vertexBuffer, \
	nullptr); 

#define D3DCREATE_INDEXBUFFER(d3dDevice, indexBuffer,  indexArray) \
d3dDevice->CreateIndexBuffer( \
	sizeof(indexArray), \
	0, \
	D3DFMT_INDEX16, \
	D3DPOOL_DEFAULT, \
	&indexBuffer, \
	nullptr);

#define D3DCREATE_VERTEXBUFFER_DYNAMIC(d3dDevice, vertexBuffer,  vertexArray, arraySize) \
d3dDevice->CreateVertexBuffer( \
	arraySize, \
	0, \
	D3DFVF3D, \
	D3DPOOL_DEFAULT, \
	&vertexBuffer, \
	nullptr); 

#define D3DCREATE_INDEXBUFFER_DYNAMIC(d3dDevice, indexBuffer,  indexArray, indexArraySize) \
d3dDevice->CreateIndexBuffer( \
	indexArraySize, \
	0, \
	D3DFMT_INDEX16, \
	D3DPOOL_DEFAULT, \
	&indexBuffer, \
	nullptr);


/********************************************************************************
 *                                                                              *
 *                                                                              *
 *                                컬러 매크로                                   *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/

 //이런 함수 있을거같은데 걍 찾아보기 귀찮아서 만듬
#define D3DCOLOR_GETA(color) color >> 24
#define D3DCOLOR_GETR(color) color << 8 >> 24
#define D3DCOLOR_GETG(color) color << 16 >> 24
#define D3DCOLOR_GETB(color) color << 24 >> 24

#define D3DCOLOR_WHITE	0xffffffff
#define D3DCOLOR_BLACK	0xff000000
#define D3DCOLOR_RED	0xffff0000
#define D3DCOLOR_GREEN	0xff00ff00
#define D3DCOLOR_YELLOW 0xffffff00
#define D3DCOLOR_VIOLET 0xffff00ff
#define D3DCOLOR_BLUE	0xff0000ff
#define D3DCOLOR_CYAN	0xff00ffff

/********************************************************************************
 *                                                                              *
 *                                                                              *
 *                                삭제 매크로                                   *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/

#define D3DSAFE_DELETE(data) do { delete data; data = nullptr; } while(0)
#define D3DSAFE_DELETE_ARRAY(arr) do { delete[] arr; arr = nullptr; } while(0)

 /********************************************************************************
  *                                                                              *
  *                                                                              *
  *                               콜백 매크로                                    *
  *                                                                              *
  *                                                                              *
  ********************************************************************************/

#define D3DCALLBACK_0(__selector__, __target__) std::bind(&__selector__, __target__)
#define D3DCALLBACK_1(__selector__, __target__) std::bind(&__selector__, __target__, std::placeholders::_1)
#define D3DCALLBACK_2(__selector__, __target__) std::bind(&__selector__, __target__, std::placeholders::_1, std::placeholders::_2)
#define D3DCALLBACK_3(__selector__, __target__) std::bind(&__selector__, __target__, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)
