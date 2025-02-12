#pragma once

class Cannon;

class CannonScene: public Scene
{
	enum CannonTurn
	{
		ONE, // 0
		TWO, // 1

		TURN_COUNT // 2
	};

public:
	CannonScene();
	~CannonScene();

	void Update() override;
	void Render(HDC hdc) override;

	// Cannon���� Fire���� �� �� �Լ� ȣ��
	void NextTurn()
	{
		// �� ��Ʈ������ �ٲ��ִ���?
		// => ������ �����ϰ�, �������� ó���� ��ȯ�� ������, �񱳰� ������
		int temp = static_cast<int>(_curTurn);
		temp++; // �� ����
		temp %= CannonTurn::TURN_COUNT; // ���� ������ ��ȯ (0, 1)
		_curTurn = static_cast<CannonTurn>(temp); // temp�� CannonTurn enum���� ��ȯ

		_timeElipse = 0.0f;
	}

private:
	shared_ptr<Cannon> _cannon;
	shared_ptr<Cannon> _cannon2;

	CannonTurn _curTurn = CannonTurn::ONE;

	float _timeElipse = 0.0f;
	float _delay = 1.0f;
};

