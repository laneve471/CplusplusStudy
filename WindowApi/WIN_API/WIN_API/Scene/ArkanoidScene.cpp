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

	_ui_hpBar->Render(hdc); // UI�� �׻� ��������
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

// TODO -> �ָ����� �غ���
// 
// map���� �ݻ�κ� ���� �Ѱ��ֱ�
// isActive default = false;
// �״� �͵� ��?
// ����� ���� �ٿ���
// ������ �����(��������) -> ����? �׷� �ʿ���?
// weakPtr ���� �ٽ� ����
// ������ �� ����
// �Լ� �����͵� �ٽ� ���� (bind �Լ�, ���� ���)
// ��������Ʈ ����?
// ���������� �������� Get ��� Set �����