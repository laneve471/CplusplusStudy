#pragma once

class Map;
class Vaus;
class ArkaBall;
class HpBar;

class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	void Update() override;
	void Render(HDC hdc) override;

	void KeyInput();

	void PlayerReset();

	void IsFall();
	void IsDead();

private:
	shared_ptr<Map> _map;
	shared_ptr<Vaus> _vaus;
	shared_ptr<ArkaBall> _ball;

	shared_ptr<class HpBar> _ui_hpBar;

	int _life = 5; // 원 모양 생명 표시
	float _hp = 1.0f; // 체력바
};

