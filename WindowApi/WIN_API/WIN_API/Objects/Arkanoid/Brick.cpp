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
	if (_isActive == false)
		return;

	RectCollider::Update();
}

void Brick::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	RectCollider::Render(hdc);
}