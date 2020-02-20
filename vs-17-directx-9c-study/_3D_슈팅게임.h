/*
 * Author      : Jungdo Yun
 * Created     : 2020-02-18 오후 3:03:00
 * Description : 내가만든 프레임워크로 간단히 게임 만들기
 */

#include "D3DApplication3D.h"

#include "D3DCube.h"
#include "D3DMeshCube.h"
#include "D3DMeshSphere.h"
#include "D3DPlane.h"

#include <vector>

#pragma once

class _3D_슈팅게임 : public D3DApplication3D
{
	CREATE_D3DAPPLICATION3D_CONSTRUCTOR(_3D_슈팅게임);
protected:
	void OnInit() override;
	void OnUpdate() override;
	void OnInitEnd() override;
private:
	void AddScore(int score);
	void SpawnBullet();
	void SpawnMonster();
private:
	//상태
	int m_score;
	bool m_lightEnabled;
	bool m_solidEnabled;
	bool m_viewCollider;

	float m_monsterGenTime;			//몬스터 젠주기
	float m_monsterGenElpasedTime;	//몬스터 젠 타이머
private:
	D3DVertexObject* player;
	D3DVertexObject* test;

	D3DMeshObject* ground;
	D3DText* scoreLabel;
	D3DText* lifeCount;

	std::vector<D3DObject*> m_monsterVec;
	std::vector<D3DObject*> m_bulletVec;
	std::vector<D3DKeyboardEvent::KeyCode> m_keyCodeVec;
	inline const std::string GetApplicationName() override { return "3D 슈팅게임"; }
};
