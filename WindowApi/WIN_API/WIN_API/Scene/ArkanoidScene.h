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

	void Init();

	void Update() override;
	void Render(HDC hdc) override;

	void KeyInput();

	void PlayerReset();

	void IsFall();
	void LoseLife();

	void GameReset();

private:
	shared_ptr<Map> _map;
	shared_ptr<Vaus> _vaus;

	shared_ptr<class HpBar> _ui_hpBar;
};

