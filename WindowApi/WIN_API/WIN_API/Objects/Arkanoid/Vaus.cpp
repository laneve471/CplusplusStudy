#include "framework.h"
#include "Vaus.h"
#include "ArkaBall.h"

Vaus::Vaus()
	: RectCollider(Vector(700, 600), Vector(60, 15))
{
	_brush = CreateSolidBrush(WHITE);
}

Vaus::~Vaus()
{
	DeleteObject(_brush);
}

void Vaus::Update()
{
	RectCollider::Update();
}

void Vaus::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	RectCollider::Render(hdc);

}

void Vaus::MoveLeft()
{
	if (GetCenter().x - GetHalfSize().x > ALKA_MAP_LEFT)
		SetCenter(GetCenter() + Vector(-1, 0) * _speed);
}

void Vaus::MoveRight()
{
	if (GetCenter().x + GetHalfSize().x < ALKA_MAP_RIGHT)
		SetCenter(GetCenter() + Vector(1, 0) * _speed);
}