#pragma once

// h는 선언부
// h, cpp 결합 => 링커
#include "Creature/Creature.h"

// 전방선언
//  : 해당 클래스가 존재한다는 것만 컴파일러에게 알려줌
// - #include 대신 전방선언을 사용하여 컴파일 속도 개선
// - 클래스의 내부(멤버 변수, 함수)를 모름 
// - 포인터, 참조 등에 사용
// 
// => 클래스의 내부 구현을 할 때는 #include 필요
// - 클래스의 객체를 멤버 변수로 가질 때
// - 상속할 때
// - 해당 클래스의 메서드를 직접 사용할 때

class Creature;

class Player : public Creature
{
public:
	Player(int hp, int atk, string name);
	~Player();

private:
};