#pragma once

class Collider
{
public:
	Collider(Vector center);
	virtual ~Collider();

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	Vector GetCenter() { return _center; }
	void SetCenter(const Vector& pos) { _center = pos; }

	virtual bool IsCollision(const Vector& pos) abstract;
	virtual bool IsCollision(shared_ptr<Collider> other) abstract;

	void SetGreen() { _curPen = 1; }
	void SetRed() { _curPen = 2; }
	void SetBlue() { _curPen = 3; }

protected:
	UINT _curPen = 0;
	vector<HPEN> _pens;

	Vector _center;
};
