#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector center, Vector size)
	: _center(center), _halfSize(size * 0.5f)
{
	_pens.push_back(CreatePen(1, 3, GREEN));
	_pens.push_back(CreatePen(1, 3, RED));
	_pens.push_back(CreatePen(1, 3, BLUE));
}

RectCollider::~RectCollider()
{
	for (auto pen : _pens)
	{
		DeleteObject(pen);
	}
}

void RectCollider::Update()
{
	//_center = LERP(_center, mousePos, 0.03f);
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPen]);
	// 가로세로 50 50인 사각형 그리기
	Rectangle(hdc, _center.x - _halfSize.x, _center.y - _halfSize.y, _center.x + _halfSize.x, _center.y + _halfSize.y);
}

// Rect 회전 안한다는 조건
bool RectCollider::IsCollision(const Vector& pos)
{
	/*Vector rectCenter = GetCenter();
	float direction_x = pos.x - rectCenter.x;
	float direction_y = pos.y - rectCenter.y;

	if (abs(direction_x) < _halfSize.x && abs(direction_y) < _halfSize.y)
		return true;*/

	if (pos.x > Left() && pos.x < Right()) // x값 사이
		if (pos.y > Top() && pos.y < Bottom()) // y값 사이
			return true;

	return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	/*Vector rectCenter_1 = GetCenter();
	Vector rectCenter_2 = other->GetCenter();

	float direction_x = rectCenter_2.x - rectCenter_1.x;
	float direction_y = rectCenter_2.y - rectCenter_1.y;

	if (abs(direction_x) < _halfSize.x + other->_halfSize.x)
		if(abs(direction_y) < _halfSize.y + other->_halfSize.y)
			return true;*/

	if (other->Left() > Right())
		return false;
	if (other->Right() < Left())
		return false;
	if (other->Top() > Bottom())
		return false;
	if (other->Bottom() < Top())
		return false;

	return true;
}
bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle)
{
	/*
	Vector circleCenter = circle->GetCenter();
	float radius = circle->GetRadius();

	if (circleCenter.y > Top() && circleCenter.y < Bottom()) {
		//if ((_center - circleCenter).Length() < _halfSize.x + radius)
		if (circleCenter.x < Right() + radius && circleCenter.x > Left() - radius)
			return true;
	}
	else if (circleCenter.x < Right() && circleCenter.x > Left()) {
		//if ((_center - circleCenter).Length() < _halfSize.y + radius)
		if (circleCenter.y > Top() - radius && circleCenter.y < Bottom() + radius)
			return true;
	}
	else {
		if (circle->IsCollision(LeftTop()))
			return true;
		if (circle->IsCollision(RightTop()))
			return true;
		if (circle->IsCollision(LeftBottom()))
			return true;
		if (circle->IsCollision(RightBottom()))
			return true;
	}

	// TODO : 원 사각형 충돌 구현
	return false;
    */
	// 결과값의 자료형, 매개변수
	// 1. 벡터 내적
	// 2. 벡터 외적

	Vector dir = circle->GetCenter() - GetCenter();
	Vector rightV = Vector(1, 0);
	Vector upV = Vector(0, -1);

	// 예외 처리
	float length = dir.Length();
	float rectHalfLength = _halfSize.Length();
	float circleRadius = circle->GetRadius();

	if (length > rectHalfLength + circleRadius)
		return false;

	// x축 내적
	float lengthX = abs(rightV.Dot(dir));
	if (lengthX > _halfSize.x + circleRadius)
		return false;

	// y축 내적
	float lengthY = abs(upV.Dot(dir));
	if (lengthY > _halfSize.y + circleRadius)
		return false;

	return true;
}