#pragma once

class Brick;
class Vaus;

class ArkaBall : public CircleCollider
{
public:
	ArkaBall();
	~ArkaBall();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void Fire();

	void ReflectByBrick(shared_ptr<Brick>& brick);
	void ReflectByVaus(shared_ptr<Vaus> vaus);
	void ReflectByWall();

	Vector& GetDir() { return _dir; }

	bool isActive = false;
private:
	HBRUSH _brush;

	Vector _dir;
};


