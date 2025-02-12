#pragma once

class Cannon;

class Barrel
{
public:

	Barrel(shared_ptr<CircleCollider> cannonBody);
	~Barrel();

	void Update();
	void Render(HDC hdc);

	Vector GetDir() { return _barrelDir; }
	void SetDir(Vector dir) { _barrelDir = dir.NormalVector(); }

	float GetAngle() { return _angle; }
	void SetAngle(float angle) { _angle = angle; }

	Vector GetMuzzle() { return _barrel->end; }

private:
	weak_ptr<CircleCollider> _cannonBody;
	shared_ptr<Line> _barrel;

	Vector		_barrelDir;
	float		_barrelLength;
	float		_angle;
};

