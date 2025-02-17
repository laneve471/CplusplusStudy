#include "framework.h"
#include "Item.h"

Item::Item()
	: CircleCollider(Vector(0, 0), 5)
{
}

Item::~Item()
{
}

void Item::Update()
{
	if (_isActive == false)
		return;

	CircleCollider::Update();

	if (_canFalling)
		SetCenter(GetCenter() + Vector(0, 1) * _speed);
}

void Item::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	CircleCollider::Render(hdc);
}
