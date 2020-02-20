#include "_공부용_3D어플리케이션.h"
#include "D3DText.h"

#include <iostream>
#include <algorithm>

using namespace std;



float getInternal(D3DXVECTOR2& a, D3DXVECTOR2& b) {
	return a.x * b.x + a.y + b.y;
}

float getAmount(D3DXVECTOR2 v) {
	return  pow(v.x, 2.0) + (v.y, 2.0);
}

float getDegree(D3DXVECTOR2& a, D3DXVECTOR2& b)
{
	 float rad =  getInternal(a, b) / (getAmount(a) * getAmount(b));
	 return  D3DXToDegree(acos(rad));
}

void _공부용_3D어플리케이션::OnInit()
{
	D3DXVECTOR2 a{ -1.0f,	10.0f };
	D3DXVECTOR2 b{	3.0f,	 1.0f };


	testText = m_objectFactory->CreateText("스케일링 테스트");
	testText->SetPositionX(0.0f);
	testText->SetPositionY(0.0f);
	testText->SetColor(D3DColor::RED);
	testText->SetScaleX(0.5f);
	testText->SetFontSize(50);
	this->Add(testText);

	D3DAxis* axis = m_objectFactory->CreateAxis(1000.0f);
	this->Add(axis);

	plane = m_objectFactory->CreatePlane(20, 20, 1.0f);
	plane->SetPosition(-50, 50, 0);
	plane->SetSolid(true);
	this->Add(plane);

	plane = m_objectFactory->CreatePlane(20, 20, 1.0f);
	plane->SetPosition(-50, 50, 0);
	plane->SetSolid(false);
	this->Add(plane);

	this->Add(m_objectFactory->CreateLine(D3DPoint3D(-30.0f, 60.0f, 0.0f), D3DPoint3D(-30.0f, 60.0f - 20.0f, 0.0f) ));
	this->Add(m_objectFactory->CreateLine(D3DPoint3D(-30.0f + 10.0f, 60.0f, 0.0f), D3DPoint3D(-30.0f + 10.0f, 60.0f - 20.0f, 0.0f)));

	triangle = m_objectFactory->CreateTriangleWithNormalVector(10.0f);
	triangle->SetLighting(false);
	triangle->SetVertexColor(D3DCOLOR_RED);
	triangle->SetPosition(0, 30, 0);
	this->Add(triangle);

	cubeLeft = m_objectFactory->CreateMeshCube(8.0f);
	cubeLeft->SetPosition(-10, 60, 0);
	cubeLeft->SetSolid(false);
	this->Add(cubeLeft);

	cubeRight = m_objectFactory->CreateMeshCube(10.0f);
	cubeRight->SetPosition(10, 60, 0);
	cubeRight->SetSolid(true);
	this->Add(cubeRight);

	sphereRight = m_objectFactory->CreateSphere(10);
	sphereRight->SetPosition(-30, 30, 0);
	sphereRight->SetLighting(true);
	this->Add(sphereRight);

	texture = m_objectFactory->CreatePlaneWithTexture(10.0f, "ff");
	texture->SetSolid(true);
	texture->SetLighting(false);
	texture->SetScale(2.0f, 2.0f, 2.0f);
	texture->SetPosition(30, 60, 0);
	this->Add(texture);




	

	//hyperRectangle = m_objectFactory->CreateHypderRectangle(10.0f, 30.0f, 40.0f);
	//hyperRectangle->SetPosition(30.0f, 30.0f, 0.0f);
	//hyperRectangle->SetLighting(false);
	//hyperRectangle->SetSolid(false);
	//this->Add(hyperRectangle);


	//sphereLeft = m_objectFactory->CreateSphere(7.5);
	//sphereLeft->SetPosition(-50, 30, 0);
	//sphereLeft->SetSolid(false);
	//sphereLeft->SetLighting(true);
	//this->Add(sphereLeft);


	
}

void _공부용_3D어플리케이션::OnUpdate()
{

	//static bool turnSwitch = false;
	////스케일링 테스트
	//if (turnSwitch == false && testText->GetScaleX() <= 2.0f)
	//	testText->SetScaleX(testText->GetScaleX() + 0.005f);
	//else
	//	turnSwitch = true;

	//if (turnSwitch == true && testText->GetScaleX() >= 0.5f)
	//	testText->SetScaleX(testText->GetScaleX() - 0.005f);
	//else
	//	turnSwitch = false;



	////바닥 회전 테스트
	//hyperRectangle->SetRotationY(hyperRectangle->GetRotationY() + 0.6f);

	////바닥 회전 테스트
	//plane->SetRotationX(plane->GetRotationX() + 0.3f);

	////삼각형 회전 테스트
	//triangle->SetRotationY(triangle->GetRotationY() + 0.5f);

	//큐브 회전 테스트
	/*cubeLeft->SetRotationX(cubeLeft->GetRotationX() + 0.1f);
	cubeRight->SetRotationX(cubeRight->GetRotationX() + 0.1f);

	

	cubeLeft->SetRotationY(cubeLeft->GetRotationY() + 0.1f);
	cubeRight->SetRotationY(cubeRight->GetRotationY() + 0.1f);*/

	//cubeLeft->SetRotationZ(cubeLeft->GetRotationZ() + 0.1f);
	//cubeRight->SetRotationZ(cubeRight->GetRotationZ() + 0.1f);

	//삼각형 회전
	//triangle->SetRotationZ(triangle->GetRotationZ() + 0.5f);


	for (int i = 0; i < m_keyCodeVec.size(); i++) {
		if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_W) {
			
		}
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_S) {
		}
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_D) {
		}
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_A) {
		}
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_L) {
		}
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_J) {
		}
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_LEFT_CTRL) {
		}
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_SPACE) {
		}

		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_R) {
		}
	}
}

