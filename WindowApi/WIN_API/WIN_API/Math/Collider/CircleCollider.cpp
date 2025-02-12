#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
	: Collider(center), _radius(radius)
{
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPen]);

	Ellipse(hdc, _center.x - _radius, _center.y - _radius, _center.x + _radius, _center.y + _radius);
}

bool CircleCollider::IsCollision(const Vector& pos)
{
	Vector circleCenter = GetCenter();
	Vector direction = pos - circleCenter;

	return direction.Length() < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<Collider> other)
{
	shared_ptr<CircleCollider> otherCircle = dynamic_pointer_cast<CircleCollider>(other);

	if (otherCircle)
	{
		Vector dir = otherCircle->GetCenter() - GetCenter();
		return dir.Length() < _radius + otherCircle->_radius;
	}

	shared_ptr<RectCollider> otherRect = dynamic_pointer_cast<RectCollider>(other);

	if (otherRect)
	{
		if (otherRect->IsCollision(shared_from_this()))
			return true;
		return false;
	}
}