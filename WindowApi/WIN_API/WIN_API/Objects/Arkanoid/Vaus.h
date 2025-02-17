#pragma once

class ArkaBall;

class Vaus : public RectCollider, public enable_shared_from_this<Vaus>
{
public:
	Vaus();
	~Vaus();

	void Init();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void Input();

	void Reset();
	void IsFall();
	void LoseLife();

	void TwoBall_Skill();
		
	vector<shared_ptr<ArkaBall>> GetBalls() { return _balls; }
	
	float GetHp() { return _hp; }
	void SetHp(float hp) { _hp = hp; }

private:
	vector<shared_ptr<ArkaBall>> _balls;

	float _speed = 10.0f;
	float _delayTime = 0.0f;

	float _hp = 1.0f;
};