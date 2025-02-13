#include "framework.h"
#include "ArkanoidScene.h"

#include "Objects/Arkanoid/Map.h"
#include "Objects/Arkanoid/ArkaBall.h"
#include "Objects/Arkanoid/Brick.h"
#include "Objects/Arkanoid/Vaus.h"
#include "Objects/Arkanoid/HpBar.h"

ArkanoidScene::ArkanoidScene()
{
	_map = make_shared<Map>();
	_vaus = make_shared<Vaus>();
	_ball = make_shared<ArkaBall>();

	_ui_hpBar = make_shared<HpBar>(Vector(700, 670), Vector(500, 20));

	_map->SetCount(_life);
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_map->Update();
	_ui_hpBar->Update();
	_ui_hpBar->SetValue(_hp);

	_vaus->Update();

	_ball->ReflectByVaus(_vaus);
	_ball->ReflectByWall();
	_ball->Update();

	for (auto bricks : _map->GetBricks())
	{
		for (auto brick : bricks)
		{
			_ball->ReflectByBrick(brick);
		}
	}

	KeyInput();
	IsFall();
	IsDead();
}

void ArkanoidScene::Render(HDC hdc)
{
	_map->Render(hdc);
	_vaus->Render(hdc);
	_ball->Render(hdc);

	_ui_hpBar->Render(hdc); // UI는 항상 마지막에
}

void ArkanoidScene::KeyInput()
{
	if (GetKeyState('A') & 0x8000)
	{
		_vaus->MoveLeft();
	}
	if (GetKeyState('D') & 0x8000)
	{
		_vaus->MoveRight();
	}
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		_ball->Fire();
	}
}

void ArkanoidScene::PlayerReset()
{
	_ball->isActive = false;
	_ball->SetCenter(Vector(700, 550));
	_ball->GetDir() = Vector(0, 0);

	_vaus->SetCenter(Vector(700, 600));
}

void ArkanoidScene::IsFall()
{
	if (_ball->GetCenter().y + _ball->GetRadius() >= WIN_HEIGHT)
	{
		PlayerReset();

		_life--;
		_map->SetCount(_life);

		_hp -= 0.2f;
	}
}

void ArkanoidScene::IsDead()
{
	bool gamePlay = false;

	for (auto& bricks : _map->GetBricks())
	{
		for (auto& brick : bricks)
		{
			if (brick->isActive == true)
			{
				gamePlay = true;
				break;
			}
		}
	}

	if (_life == 0 || !gamePlay)
	{
		PlayerReset();

		for (auto& bricks : _map->GetBricks())
		{
			for (auto& brick : bricks)
			{
				brick->isActive = true;
			}
		}

		_life = 5;
		_map->SetCount(_life);

		_hp = 1.0f;
	}
}

// TODO -> 주말까지 해보기
// 
// map으로 반사부분 전부 넘겨주기
// isActive default = false;
// 죽는 것도 맵?
// 생명과 공은 바에게
// 아이템 만들기(벽돌에게) -> 별로? 그럼 맵에게?
// weakPtr 사용법 다시 공부
// 렌더링 펜 정리
// 함수 포인터도 다시 공부 (bind 함수, 선언 등등)
// 델리게이트 패턴?
// 참조형으로 가져오는 Get 대신 Set 만들기