#pragma once

class Brick;
class Vaus;

class ArkaBall : public CircleCollider
{
public:
	friend class Vaus;

	ArkaBall(shared_ptr<Vaus> vaus);
	~ArkaBall();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void Reset();
	void Fire();
	void Reflection();

	Vector GetDir() { return _dir; }
	void SetDir(Vector dir) { _dir = dir; }

	bool GetActive() { return _isActive; }
	void SetActive(bool active) { _isActive = active; }
	
	bool GetFired() { return _isFired; }
	void SetFired(bool active) { _isFired = active; }

private:
	weak_ptr<Vaus> _vaus;

	Vector _dir;

	float _speed = 3.0f;

	bool _isActive = false;
	bool _isFired = false;
};
