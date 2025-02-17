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
	_map->SetCount(_vaus->GetHp() * 5);		// 원 모양 생명 표시

	_ui_hpBar->Update(); 
	_ui_hpBar->SetValue(_vaus->GetHp());	// 체력바

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

	_ui_hpBar->Render(hdc); // UI는 항상 마지막에
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
// 아이템 만들기(벽돌에게) -> 별로? 그럼 맵에게?
// weakPtr 사용법 공부
// 함수 포인터 공부 (bind 함수, 선언 등등)
// 델리게이트 패턴 찾아보기