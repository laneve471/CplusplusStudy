#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_circle = make_shared<CircleCollider>(Vector(-1000, -1000), 10);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	if (_isActive == false) return;

	_circle->Update();

	// 화면 밖으로 나가면 소멸
	/*if (_circle->GetCenter().x > WIN_WIDTH || _circle->GetCenter().x < 0
		|| _circle->GetCenter().y > WIN_HEIGHT || _circle->GetCenter().y < 0)
		isActive = false;*/

	// 반사
	Vector center = _circle->GetCenter();
	if (center.x < 0 || center.x > WIN_WIDTH)
		_dir.x *= -1;
	if (center.y < 0 || center.y > WIN_HEIGHT)
		_dir.y *= -1;

	_circle->SetCenter(_circle->GetCenter() + _dir * _ballSpeed);
}

void Ball::Render(HDC hdc)
{
	if (_isActive == false) return;

	_circle->Render(hdc);
}

void Ball::Fire(Vector dir)
{
	_dir = dir.NormalVector();
}

void Ball::AddVector(Vector v)
{
	if (_isActive == false) return;

	_circle->SetCenter(_circle->GetCenter() + v);
}
