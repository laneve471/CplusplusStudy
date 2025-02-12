#pragma once

class Creature
{
public:
	Creature(int hp, int atk);
	virtual ~Creature(); // 자식 클래스 객체가 부모 포인터를 통해 삭제될 때 자식 클래스의 소멸자도 호출

	virtual void Attack(shared_ptr<Creature> other) abstract;
	virtual void TakeDamage(int amount, shared_ptr<Creature> attacker = nullptr);

	bool IsDead();

	// C# getset
	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

protected:
	int _hp;
	int _atk;
	string _name;
};