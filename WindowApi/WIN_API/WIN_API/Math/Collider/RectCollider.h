#pragma once
class RectCollider
{
public:
	RectCollider(Vector center, Vector size);
	~RectCollider();

	void Update();
	void Render(HDC hdc);

	Vector GetCenter() { return _center; }
	Vector GetHalfSize() { return _halfSize; }
	void SetCenter(const Vector& pos) { _center = pos; }

	Vector& Center() { return _center; }

	void SetGreen() { _curPen = 0; }
	void SetRed() {_curPen = 1; }
	void SetBlue() { _curPen = 2; }

	bool IsCollision(const Vector& pos);
	bool IsCollision(shared_ptr<RectCollider> other);
	bool IsCollision(shared_ptr<class CircleCollider> circle);

	int Left() { return _center.x - _halfSize.x; }
	int Right() { return _center.x + _halfSize.x; }
	int Top() { return _center.y - _halfSize.y; }
	int Bottom() { return _center.y + _halfSize.y; }

	Vector LeftTop() { return Vector(Left(), Top()); }
	Vector RightTop() { return Vector(Right(), Top()); }
	Vector LeftBottom() { return Vector(Left(), Bottom()); }
	Vector RightBottom() { return Vector(Right(), Bottom()); }

private:
	UINT				_curPen = 0;
	vector<HPEN>		_pens;

	Vector				_center;
	Vector				_halfSize;
};

// 전방선언이 뭐지

