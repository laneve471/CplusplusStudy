#pragma once

// h�� �����
// h, cpp ���� => ��Ŀ
#include "Creature/Creature.h"

// ���漱��
//  : �ش� Ŭ������ �����Ѵٴ� �͸� �����Ϸ����� �˷���
// - #include ��� ���漱���� ����Ͽ� ������ �ӵ� ����
// - Ŭ������ ����(��� ����, �Լ�)�� �� 
// - ������, ���� � ���
// 
// => Ŭ������ ���� ������ �� ���� #include �ʿ�
// - Ŭ������ ��ü�� ��� ������ ���� ��
// - ����� ��
// - �ش� Ŭ������ �޼��带 ���� ����� ��

class Creature;

class Player : public Creature
{
public:
	Player(int hp, int atk, string name);
	~Player();

private:
};