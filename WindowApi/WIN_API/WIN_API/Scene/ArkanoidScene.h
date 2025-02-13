#pragma once

class Map;
class Vaus;
class ArkaBall;

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

	int _life = 3;
};

