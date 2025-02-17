#include "framework.h"
#include "Map.h"

#include "Brick.h"
#include "Vaus.h"
#include "ArkaBall.h"
#include "Item.h"

Map::Map()
{
	Vector offset = Vector(500, 200);
	_pen = CreatePen(1, 3, WHITE);

	_bricksWithItems.resize(_countY);
	for (int y = 0; y < _countY; y++)
	{
		_bricksWithItems[y].reserve(_countX);
		for (int x = 0; x < _countX; x++)
		{
			shared_ptr<Brick> brick = make_shared<Brick>();
			shared_ptr<Item> item = make_shared<Item>();
			Vector pos;
			pos.x = x * 65;
			pos.y = y * 20;
			brick->SetCenter(pos + offset);
			item->SetCenter(pos + offset);

			_bricksWithItems[y].push_back({ brick, item });
		}
	}
}

Map::~Map()
{
}

void Map::Init(shared_ptr<Vaus> vaus)
{
	for (auto& bricks : _bricksWithItems)
	{
		for (auto& pair : bricks)
		{
			pair.first->SetActive(true);
			pair.second->SetActive(true);
			pair.second->SetSkill(std::bind(&Vaus::TwoBall_Skill, vaus));
		}
	}
}

void Map::Update()
{
	for (auto& bricks : _bricksWithItems)
	{
		for (auto& pair : bricks)
		{
			pair.first->Update();
			pair.second->Update();
		}
	}
}

void Map::Render(HDC hdc)
{
	for (auto& bricks : _bricksWithItems)
	{
		for (auto& pair : bricks)
		{
			pair.first->Render(hdc);
			pair.second->Render(hdc);
		}
	}

	SelectObject(hdc, _pen);
	MoveToEx(hdc, ALKA_MAP_LEFT, WIN_HEIGHT, NULL);
	LineTo(hdc, ALKA_MAP_LEFT, ALKA_MAP_TOP);
	LineTo(hdc, ALKA_MAP_RIGHT, ALKA_MAP_TOP);
	LineTo(hdc, ALKA_MAP_RIGHT, WIN_HEIGHT);

	for (int i = 0; i < count; i++)
	{
		Ellipse(hdc, (200 + i * 20), 500, (210 + i * 20), 510);
	}
}

void Map::ReflectionByBrick(shared_ptr<ArkaBall> ball)
{
	for (auto& bricks : _bricksWithItems)
	{
		for (auto& brick : bricks)
		{
			if (!brick.first->IsCollision(ball) || brick.first->GetActive() == false)
				continue;

			brick.first->SetActive(false);
			brick.second->SetFalling(true);
			
			int right = brick.first->Right();
			int top = brick.first->Top();

			Vector rightV = Vector(1, 0);
			Vector dir1 = Vector(right, top) - brick.first->GetCenter();
			Vector dir2 = ball->GetCenter() - brick.first->GetCenter();
			dir1.Normalize(); dir2.Normalize();
			float a = rightV.Cross(dir1);
			float b = rightV.Cross(dir2);

			Vector dir = ball->GetDir();

			if (b <= a || b >= -a)
				dir.y *= -1;
			else
				dir.x *= -1;

			ball->SetDir(dir);
		}
	}
}

void Map::GetItems(shared_ptr<Vaus> vaus)
{
	for (auto& bricks : _bricksWithItems)
	{
		for (auto& pair : bricks)
		{
			if (pair.second->IsCollision(vaus) && pair.second->GetActive())
			{
				pair.second->SetActive(false);
				pair.second->ActiveSkill();
			}
		}
	}
}

bool Map::IsClear()
{
	for (auto& bricks : _bricksWithItems)
	{
		for (auto& brick : bricks)
		{
			if (brick.first->GetActive() == true)
			{
				return false;
			}
		}
	}

	return true;
}