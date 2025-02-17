#include "framework.h"
#include "ArkanoidScene.h"

#include "Objects/Arkanoid/Map.h"
#include "Objects/Arkanoid/ArkaBall.h"
#include "Objects/Arkanoid/Brick.h"
#include "Objects/Arkanoid/Vaus.h"
#include "Objects/Arkanoid/HpBar.h"

ArkanoidScene::ArkanoidScene()
{
	_vaus = make_shared<Vaus>();
	_map = make_shared<Map>();

	_vaus->Init();
	_map->Init(_vaus);

	_ui_hpBar = make_shared<HpBar>(Vector(700, 670), Vector(500, 20));
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_vaus->Update();
	_vaus->Input();

	_map->Update();
	_map->SetCount(_vaus->GetHp() * 5);		// �� ��� ���� ǥ��

	_ui_hpBar->Update(); 
	_ui_hpBar->SetValue(_vaus->GetHp());	// ü�¹�

	for (auto& ball : _vaus->GetBalls())
	{
		if (ball->GetActive() == false)
			continue;

		_map->ReflectionByBrick(ball);
	}

	_map->GetItems(_vaus);

	GameReset();
}

void ArkanoidScene::Render(HDC hdc)
{
	_map->Render(hdc);
	_vaus->Render(hdc);

	_ui_hpBar->Render(hdc); // UI�� �׻� ��������
}

void ArkanoidScene::GameReset()
{
	if (_vaus->GetHp() < 0.1f || _map->IsClear())
	{
		_vaus->Init();
		_map->Init(_vaus);
	}
}

// TODO
// 
// ������ �����(��������) -> ����? �׷� �ʿ���?
// weakPtr ���� ����
// �Լ� ������ ���� (bind �Լ�, ���� ���)
// ��������Ʈ ���� ã�ƺ���