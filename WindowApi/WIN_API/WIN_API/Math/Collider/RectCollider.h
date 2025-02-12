#pragma once

class RectCollider : public Collider
{
public:
	RectCollider(Vector center, Vector size);
	virtual ~RectCollider();

	void Update();
	void Render(HDC hdc);

	Vector GetHalfSize() { return _halfSize; }

	bool IsCollision(const Vector& pos);
	bool IsCollision(shared_ptr<Collider> other);

	int Left() { return _center.x - _halfSize.x; }
	int Right() { return _center.x + _halfSize.x; }
	int Top() { return _center.y - _halfSize.y; }
	int Bottom() { return _center.y + _halfSize.y; }

	Vector LeftTop() { return Vector(Left(), Top()); }
	Vector RightTop() { return Vector(Right(), Top()); }
	Vector LeftBottom() { return Vector(Left(), Bottom()); }
	Vector RightBottom() { return Vector(Right(), Bottom()); }

private:
	Vector				_halfSize;
};