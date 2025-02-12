#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector center, Vector size)
	: Collider(center), _halfSize(size * 0.5f)
{
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPen]);
	
	Rectangle(hdc, _center.x - _halfSize.x, _center.y - _halfSize.y, _center.x + _halfSize.x, _center.y + _halfSize.y);
}

// Rect 회전 안한다는 조건
bool RectCollider::IsCollision(const Vector& pos)
{
	if (pos.x > Left() && pos.x < Right()) // x값 사이
		if (pos.y > Top() && pos.y < Bottom()) // y값 사이
			return true;

	return false;
}

bool RectCollider::IsCollision(shared_ptr<Collider> other)
{
	shared_ptr<RectCollider> otherRect = dynamic_pointer_cast<RectCollider>(other);

	if (otherRect)
	{
		if (otherRect->Left() > Right())
			return false;
		if (otherRect->Right() < Left())
			return false;
		if (otherRect->Top() > Bottom())
			return false;
		if (otherRect->Bottom() < Top())
			return false;
		return true;
	}

	shared_ptr<CircleCollider> otherCircle = dynamic_pointer_cast<CircleCollider>(other);

	if (otherCircle)
	{
		Vector dir = otherCircle->GetCenter() - GetCenter();
		Vector rightV = Vector(1, 0);
		Vector upV = Vector(0, -1);

		// 예외 처리
		float length = dir.Length();
		float rectHalfLength = _halfSize.Length();
		float circleRadius = otherCircle->GetRadius();

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
}



#pragma region 내적 없이 사각형 - 원 충돌 구현
//bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle)
//{
//	/*
//	Vector circleCenter = circle->GetCenter();
//	float radius = circle->GetRadius();
//
//	if (circleCenter.y > Top() && circleCenter.y < Bottom()) {
//		//if ((_center - circleCenter).Length() < _halfSize.x + radius)
//		if (circleCenter.x < Right() + radius && circleCenter.x > Left() - radius)
//			return true;
//	}
//	else if (circleCenter.x < Right() && circleCenter.x > Left()) {
//		//if ((_center - circleCenter).Length() < _halfSize.y + radius)
//		if (circleCenter.y > Top() - radius && circleCenter.y < Bottom() + radius)
//			return true;
//	}
//	else {
//		if (circle->IsCollision(LeftTop()))
//			return true;
//		if (circle->IsCollision(RightTop()))
//			return true;
//		if (circle->IsCollision(LeftBottom()))
//			return true;
//		if (circle->IsCollision(RightBottom()))
//			return true;
//	}
#pragma endregion