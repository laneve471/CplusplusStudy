#include "framework.h"
#include "Map.h"

#include "Brick.h"
#include "Vaus.h"
#include "ArkaBall.h"

Map::Map()
{
	Vector offset = Vector(500, 200);
	_pen = CreatePen(1, 3, WHITE);

	_bricks.resize(_countY);
	for (int y = 0; y < _countY; y++)
	{
		_bricks[y].reserve(_countX);
		for (int x = 0; x < _countX; x++)
		{
			shared_ptr<Brick> brick = make_shared<Brick>();
			Vector pos;
			pos.x = x * 65;
			pos.y = y * 20;
			brick->SetCenter(pos + offset);

			_bricks[y].push_back(brick);
		}
	}
}

Map::~Map()
{
}

void Map::Update()
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			if (brick->isActive == false)
				continue;
			brick->Update();
		}
	}
}

void Map::Render(HDC hdc)
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			if (brick->isActive == false)
				continue;
			brick->Render(hdc);
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
