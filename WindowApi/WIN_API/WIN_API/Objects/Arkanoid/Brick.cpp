#include "framework.h"
#include "Brick.h"

Brick::Brick()
	: RectCollider(Vector(0, 0), Vector(60, 15))
{
}

Brick::~Brick()
{
}

void Brick::Update()
{
	RectCollider::Update();
}

void Brick::Render(HDC hdc)
{
	RectCollider::Render(hdc);
}