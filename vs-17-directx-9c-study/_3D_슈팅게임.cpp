#include "_3D_���ð���.h"

#include "Random.h"

#include <iostream>
#include <algorithm>

using namespace std;



void _3D_���ð���::OnInit()
{
	m_score = 0;
	m_monsterGenTime = 0.5f;
	m_monsterGenElpasedTime = 0.0f;

	#pragma region ��ü �ʱ�ȭ
	D3DAxis* axis = m_objectFactory->CreateAxis(1000.0f);
	this->Add(axis);

	ground = m_objectFactory->CreatePlane(10, 20, 3.0f);
	D3DCOLORVALUE value;
	value.a = 0.6;
	value.r = 1.0;
	value.b = 1.0;
	value.g = 0.0;
	ground->SetMaterialDiffuse(value);
	ground->SetRotationX(90.0f);
	this->Add(ground);

	player = m_objectFactory->CreateTriangleWithNormalVector(3.0f);
	player->SetVertexColor(0xaaaaaaaa);
	player->SetSphereCollider(1.5f);
	player->SetPositionY(-25.0f);
	player->SetPositionZ(-1.0f);
	this->Add(player);

	scoreLabel = m_objectFactory->CreateText("���� : 00000000");
	scoreLabel->SetColor(D3DColor::GREEN);
	scoreLabel->SetFontSize(50.0f);
	scoreLabel->SetPosition(0.0f, 0.0f, 0.0f);
	this->Add(scoreLabel);
	#pragma endregion			

	#pragma region Ű���� �̺�Ʈ ó��
	D3DKeyboardEventListener* keyboardEventListener = new D3DKeyboardEventListener();
	keyboardEventListener->onKeyPressed = [this](D3DKeyboardEvent* event) {
		auto iter = std::find(m_keyCodeVec.begin(), m_keyCodeVec.end(), event->GetKeyCode());
		if (iter == m_keyCodeVec.end())
			m_keyCodeVec.push_back(event->GetKeyCode());


		//���� ������
		if (event->GetKeyCode() == D3DKeyboardEvent::KeyCode::KEY_F1) {
			std::for_each(m_children.begin(), m_children.end(), [this](std::pair<D3DObject*, D3DObject* > pair) {
					pair.second->SetLighting(m_lightEnabled);
				});
			m_lightEnabled = !m_lightEnabled;
		}

		//������ ǥ�� ����
		else if (event->GetKeyCode() == D3DKeyboardEvent::KeyCode::KEY_F2) {
			std::for_each(m_children.begin(), m_children.end(), [this](std::pair<D3DObject*, D3DObject* > pair) {
					pair.second->SetSolid(m_solidEnabled);
				});
			m_solidEnabled = !m_solidEnabled;
		}

		//��ü�� �ݶ��̴� �����ֱ� ����
		else if (event->GetKeyCode() == D3DKeyboardEvent::KeyCode::KEY_F3) {
			std::for_each(m_children.begin(), m_children.end(), [this](std::pair<D3DObject*, D3DObject* > pair) {
				pair.second->SetViewCollider(m_viewCollider);
				});
			m_viewCollider = !m_viewCollider;
		}

		//�Ѿ� �߽�
		else if (event->GetKeyCode() == D3DKeyboardEvent::KeyCode::KEY_LEFT_CTRL) {
			SpawnBullet();
		}
	};


	keyboardEventListener->onKeyReleased = [this](D3DKeyboardEvent* event) {

		for (auto i = m_keyCodeVec.begin(); i != m_keyCodeVec.end();) {

			if ((*i) == event->GetKeyCode())
				i = m_keyCodeVec.erase(i);
			else
				i++;
		}
	};

#pragma endregion

	m_eventDispatcher->AddEventListener(keyboardEventListener);
}

void _3D_���ð���::OnUpdate()
{
	
	//�÷��̾� �̵�ó��
	for (int i = 0; i < m_keyCodeVec.size(); i++) {
		if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_I)
			player->SetPositionY(player->GetPositionY() + 0.2f);
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_K)
			player->SetPositionY(player->GetPositionY() - 0.2f);
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_L)
			player->SetPositionX(player->GetPositionX() + 0.2f);
		else if (m_keyCodeVec[i] == D3DKeyboardEvent::KeyCode::KEY_J)
			player->SetPositionX(player->GetPositionX() - 0.2f);
	}

	//���� ��
	m_monsterGenElpasedTime += m_framePerSec;
	if (m_monsterGenElpasedTime >= m_monsterGenTime) {
		 m_monsterGenElpasedTime = 0.0f;
		 SpawnMonster();
	}

	//�Ѿ� �̵�ó��
	std::for_each(m_bulletVec.begin(), m_bulletVec.end(), [this](D3DObject* obj) {obj->SetPositionY(obj->GetPositionY() + 0.6f); });

	//�Ѿ� ���Ϳ� �浹üũ
	for (int i = 0; i < m_bulletVec.size(); i++) {
		for (int j = 0; j < m_monsterVec.size(); j++) {
			if (m_bulletVec[i]->IsCollided(m_monsterVec[j])) {
				Remove(m_bulletVec[i]);
				Remove(m_monsterVec[j]);

				m_bulletVec.erase(m_bulletVec.begin() + i);
				m_monsterVec.erase(m_monsterVec.begin() + j);
				AddScore(100);
				break;
			}
		}
	}

	//�Ѿ� ���� �浹üũ
	for (int i = 0; i < m_bulletVec.size(); i++) {
		if (m_bulletVec[i]->GetPositionY() >= 30.0f) {
			Remove(m_bulletVec[i]);
			m_bulletVec.erase(m_bulletVec.begin() + i);
			break;
		}
	}

	//���� �̵�ó��
	for (int i = 0; i < m_monsterVec.size(); i++)
		m_monsterVec[i]->SetPositionY(m_monsterVec[i]->GetPositionY() - 0.2f);

	//���� ���� �浹üũ
	for (int i = 0; i < m_monsterVec.size(); i++) {
		if (m_monsterVec[i]->GetPositionY() <= -30.0f) {
			Remove(m_monsterVec[i]);
			m_monsterVec.erase(m_monsterVec.begin() + i);
			break;
		}
	}
}

void _3D_���ð���::OnInitEnd()
{
	//ī�޶� ��ġ ����
	m_camera->SetLookAt(D3DPoint3D(0.0f, 0.0f, 0.0f));
	m_camera->SetPosition(0, 0, -70);
}

void _3D_���ð���::AddScore(int score)
{
	m_score += score;
	scoreLabel->SetText(to_string(m_score));
}

void _3D_���ð���::SpawnBullet()
{
	D3DVertexObject* bullet = m_objectFactory->CreateHypderRectangle(0.2f, 0.2f, 1.0f);
	bullet->SetSphereCollider(1.0f);
	bullet->SetPosition(player->GetPosition());
	bullet->SetVertexColor(D3DCOLOR_VIOLET);
	bullet->SetPositionY(bullet->GetPositionY() + 1.0f);
	bullet->SetPositionZ(-1.0f);
	this->Add(bullet);

	m_bulletVec.push_back(bullet);
}

void _3D_���ð���::SpawnMonster()
{
	D3DVertexObject* monster = m_objectFactory->CreateTriangleWithNormalVector(1.5f);
	monster->SetVertexColor(D3DCOLOR_CYAN);
	monster->SetRotationZ(180.0f);
	monster->SetSphereCollider(0.75f);
	monster->SetPosition(Random::GetDouble(-15.0, 15.0f), 60.0f, -1.0f);
	this->Add(monster);

	m_monsterVec.push_back(monster);
}
