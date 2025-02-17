#include "framework.h"
#include "ArkaBall.h"

#include "Brick.h"
#include "Vaus.h"

ArkaBall::ArkaBall(shared_ptr<Vaus> vaus)
	: CircleCollider(Vector(700, 550), 10)
{
	_vaus = vaus;
}

ArkaBall::~ArkaBall()
{
}

void ArkaBall::Update()
{
	if (_isActive == false)
		return;

	CircleCollider::Update();
	SetCenter(GetCenter() + _dir * _speed);
	Reflection();
}

void ArkaBall::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	CircleCollider::Render(hdc);
}

void ArkaBall::Reset()
{
	_isActive = false;
	_isFired = false;
	SetCenter(Vector(700, 550));
	SetDir(Vector(0, 0));
}

void ArkaBall::Fire()
{
	_isFired = true;
	_dir = Vector(0, -1);
}

void ArkaBall::Reflection()
{
	if (_isActive == false)
		return;

	if (IsCollision(_vaus.lock()))
	{
		Vector dir = GetCenter() - _vaus.lock()->GetCenter();
		_dir = dir.NormalVector();
	}

	Vector center = GetCenter();
	float radius = GetRadius();

	if (center.x - radius <= 400 || center.x + radius >= 1000)
	{
		_dir.x *= -1;
	}

	if (center.y - radius <= 100)
	{
		_dir.y *= -1;
	}
}