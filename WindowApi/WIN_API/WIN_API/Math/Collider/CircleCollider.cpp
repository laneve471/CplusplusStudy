#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
	: _center(center), _radius(radius)
{
	_pens.push_back(CreatePen(1, 3, GREEN));
	_pens.push_back(CreatePen(1, 3, RED));
	_pens.push_back(CreatePen(1, 3, BLUE));
}

CircleCollider::~CircleCollider()
{
	for (auto pen : _pens)
	{
		DeleteObject(pen);
	}
}

void CircleCollider::Update()
{
	//_center = LERP(_center, mousePos, 0.1f);
}

void CircleCollider::Render(HDC hdc)
{
	//float left = _center.x - _radius
	// 가로세로 50 50인 사각형 그리기
	SelectObject(hdc, _pens[_curPen]);

	Ellipse(hdc, _center.x - _radius, _center.y - _radius, _center.x + _radius, _center.y + _radius);
}

bool CircleCollider::IsCollision(const Vector& pos)
{
	Vector circleCenter = GetCenter();
	Vector direction = pos - circleCenter;

	return direction.Length() < _radius;
}
bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	Vector circleCenter_1 = GetCenter();
	Vector circleCenter_2 = other->GetCenter();
	Vector direction = (circleCenter_2 - circleCenter_1);

	return direction.Length() < _radius + other->_radius;
}
bool CircleCollider::IsCollision(shared_ptr<class RectCollider> rect)
{
	Vector rectCenter = rect->GetCenter();
	Vector halfSize = rect->GetHalfSize();

	if (_center.y > rect->Top() && _center.y < rect->Bottom()) {
		if (_center.x < rect->Right() + _radius && _center.x > rect->Left() - _radius)
			return true;
	}
	else if (_center.x < rect->Right() && _center.x > rect->Left()) {
		if (_center.y > rect->Top() - _radius && _center.y < rect->Bottom() + _radius)
			return true;
	}
	else {
		if (IsCollision(rect->LeftTop()))
			return true;
		if (IsCollision(rect->RightTop()))
			return true;
		if (IsCollision(rect->LeftBottom()))
			return true;
		if (IsCollision(rect->RightBottom()))
			return true;
	}
	

	//if (rect->IsCollision(shared_from_this()))
	//	return true;

	return false;
}