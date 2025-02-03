#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { _circle->SetCenter(pos); } // À§Ä¡º¤
	void AddForce(Vector v); // ¹æÇâº¤

	bool isActive = false;

private:
	shared_ptr<CircleCollider> _circle;

	float _ballSpeed = 3;
};

