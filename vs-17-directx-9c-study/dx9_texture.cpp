////-----------------------------------------------------------------------------
////           Name: dx9_texture.cpp
////         Author: Kevin Harris
////  Last Modified: 02/01/05
////    Description: This sample demonstrates how to texture geometry with 
////                 Direct3D.
////-----------------------------------------------------------------------------
//
//#define STRICT
//#define WIN32_LEAN_AND_MEAN
//
//#include <windows.h>
//#include <d3d9.h>
//#include <d3dx9.h>
//
////-----------------------------------------------------------------------------
//// GLOBALS
////-----------------------------------------------------------------------------
//HWND                    g_hWnd          = NULL;
//LPDIRECT3D9             g_pD3D          = NULL;
//LPDIRECT3DDEVICE9       g_pd3dDevice    = NULL;
//LPDIRECT3DVERTEXBUFFER9 g_pVertexBuffer = NULL;
//LPDIRECT3DTEXTURE9      g_pTexture      = NULL;
//
//#define D3DFVF_CUSTOMVERTEX ( D3DFVF_XYZ | D3DFVF_TEX1 )
//
//struct Vertex
//{
//    float x, y, z;
//    float tu, tv;
//};
//
//Vertex g_quadVertices[] =
//{
//	{-1.0f, 1.0f, 0.0f,  0.0f,0.0f },
//	{ 1.0f, 1.0f, 0.0f,  1.0f,0.0f },
//	{-1.0f,-1.0f, 0.0f,  0.0f,1.0f },
//	{ 1.0f,-1.0f, 0.0f,  1.0f,1.0f }
//};
//
////-----------------------------------------------------------------------------
//// PROTOTYPES
////-----------------------------------------------------------------------------
//LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//void loadTexture(void);
//void init(void);
//void shutDown(void);
//void render(void);
//
////-----------------------------------------------------------------------------
//// Name: WinMain()
//// Desc: The application's entry point
////-----------------------------------------------------------------------------
//int WINAPI wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//	WNDCLASSEX winClass; 
//	MSG        uMsg;
//
//    memset(&uMsg,0,sizeof(uMsg));
//    
//	winClass.lpszClassName = "MY_WINDOWS_CLASS";
//	winClass.cbSize        = sizeof(WNDCLASSEX);
//	winClass.style         = CS_HREDRAW | CS_VREDRAW;
//	winClass.lpfnWndProc   = WindowProc;
//	winClass.hInstance     = hInstance;
//	winClass.hIcon	       = LoadIcon(hInstance, (LPCTSTR)nullptr);
//    winClass.hIconSm	   = LoadIcon(hInstance, (LPCTSTR)nullptr);
//	winClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
//	winClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
//	winClass.lpszMenuName  = NULL;
//	winClass.cbClsExtra    = 0;
//	winClass.cbWndExtra    = 0;
//
//	if( !RegisterClassEx(&winClass) )
//		return E_FAIL;
//
//	g_hWnd = CreateWindowEx( NULL, "MY_WINDOWS_CLASS", 
//                             "Direct3D (DX9) - Texturing",
//						     WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//					         0, 0, 640, 480, NULL, NULL, hInstance, NULL );
//
//	if( g_hWnd == NULL )
//		return E_FAIL;
//
//    ShowWindow( g_hWnd, nCmdShow );
//    UpdateWindow( g_hWnd );
//
//	init();
//
//	while( uMsg.message != WM_QUIT )
//	{
//		if( PeekMessage( &uMsg, NULL, 0, 0, PM_REMOVE ) )
//		{ 
//			TranslateMessage( &uMsg );
//			DispatchMessage( &uMsg );
//		}
//        else
//		    render();
//	}
//
//	shutDown();
//
//    UnregisterClass( "MY_WINDOWS_CLASS", winClass.hInstance );
//
//	return uMsg.wParam;
//}
//
////-----------------------------------------------------------------------------
//// Name: WindowProc()
//// Desc: The window's message handler
////-----------------------------------------------------------------------------
//LRESULT CALLBACK WindowProc( HWND   hWnd, 
//							 UINT   msg, 
//							 WPARAM wParam, 
//							 LPARAM lParam )
//{
//    switch( msg )
//	{	
//        case WM_KEYDOWN:
//		{
//			switch( wParam )
//			{
//				case VK_ESCAPE:
//					PostQuitMessage(0);
//					break;
//			}
//		}
//        break;
//
//		case WM_CLOSE:
//		{
//			PostQuitMessage(0);	
//		}
//		
//        case WM_DESTROY:
//		{
//            PostQuitMessage(0);
//		}
//        break;
//
//		default:
//		{
//			return DefWindowProc( hWnd, msg, wParam, lParam );
//		}
//		break;
//	}
//
//	return 0;
//}
//
////-----------------------------------------------------------------------------
//// Name: loadTexture()
//// Desc: 
////-----------------------------------------------------------------------------
//void loadTexture( void )
//{
//	D3DXCreateTextureFromFile( g_pd3dDevice, "resource/woodfloor.bmp", &g_pTexture );
//
//	g_pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
//	g_pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
//}
//
////-----------------------------------------------------------------------------
//// Name: init()
//// Desc: 
////-----------------------------------------------------------------------------
//void init( void )
//{
//    g_pD3D = Direct3DCreate9( D3D_SDK_VERSION );
//
//    D3DDISPLAYMODE d3ddm;
//
//    g_pD3D->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &d3ddm );
//
//    D3DPRESENT_PARAMETERS d3dpp;
//    ZeroMemory( &d3dpp, sizeof(d3dpp) );
//	
//    d3dpp.Windowed               = TRUE;
//    d3dpp.SwapEffect             = D3DSWAPEFFECT_DISCARD;
//    d3dpp.BackBufferFormat       = d3ddm.Format;
//    d3dpp.EnableAutoDepthStencil = TRUE;
//    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
//    d3dpp.PresentationInterval   = D3DPRESENT_INTERVAL_IMMEDIATE;
//
//    g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd,
//                          D3DCREATE_SOFTWARE_VERTEXPROCESSING,
//                          &d3dpp, &g_pd3dDevice );
//
//	loadTexture();
//	
//	g_pd3dDevice->CreateVertexBuffer( 4*sizeof(Vertex), D3DUSAGE_WRITEONLY, 
//                                      D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, 
//                                      &g_pVertexBuffer, NULL );
//    void *pVertices = NULL;
//
//    g_pVertexBuffer->Lock( 0, sizeof(g_quadVertices), (void**)&pVertices, 0 );
//    memcpy( pVertices, g_quadVertices, sizeof(g_quadVertices) );
//    g_pVertexBuffer->Unlock();
//
//    D3DXMATRIX matProj;
//    D3DXMatrixPerspectiveFovLH( &matProj, D3DXToRadian( 45.0f ), 
//                                640.0f / 480.0f, 0.1f, 100.0f );
//    g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );
//
//	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
//}
//
////-----------------------------------------------------------------------------
//// Name: shutDown()
//// Desc: 
////-----------------------------------------------------------------------------
//void shutDown( void )
//{
//    if( g_pTexture != NULL ) 
//        g_pTexture->Release();
//
//    if( g_pVertexBuffer != NULL ) 
//        g_pVertexBuffer->Release(); 
//
//    if( g_pd3dDevice != NULL )
//        g_pd3dDevice->Release();
//
//    if( g_pD3D != NULL )
//        g_pD3D->Release();
//}
//
////-----------------------------------------------------------------------------
//// Name: render()
//// Desc: 
////-----------------------------------------------------------------------------
//void render( void )
//{
//    g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
//                         D3DCOLOR_COLORVALUE(0.0f,0.0f,0.0f,1.0f), 1.0f, 0 );
//
//    D3DXMATRIX matWorld;
//    D3DXMatrixTranslation( &matWorld, 0.0f, 0.0f, 4.0f );
//    g_pd3dDevice->SetTransform( D3DTS_WORLD, &matWorld );
//
//    g_pd3dDevice->BeginScene();
//
//	g_pd3dDevice->SetTexture(0, g_pTexture);
//    g_pd3dDevice->SetStreamSource( 0, g_pVertexBuffer, 0, sizeof(Vertex) );
//	g_pd3dDevice->SetFVF( D3DFVF_CUSTOMVERTEX );
//	
//	g_pd3dDevice->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2 );
//
//    g_pd3dDevice->EndScene();
//    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
//}
//
