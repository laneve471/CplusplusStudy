#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

// ModernCPP
// C++ 11
// - auto
//  = 무조건 초기화
//  = 남발하면 가독성 떨어짐

// - using
//  = 템플릿에서 호환 가능
// 
// - 중괄호 초기화, 초기화 리스트
// 
// - friend, default
//
// - 범위 기반 for문
//
// - tuple
//
// - string
//
// - deque
// 
// - 람다
// - std::move
// - 스마트포인터


//void(*func2)(void); // 선언
typedef void(*Func1)(void); // 타입 정의
using Func2 = void(*)(void);

struct Vector
{
	Vector() = default; // 내용없음

	float x = 10;
	float y = 2;
};

class Pet;
class Player
{
	friend Pet;
private:
	int _hp;
	int _atk;
};

class Pet
{
public:
	void CheckPlayer(Player* p)
	{
		cout << p->_hp << endl;
	}
};

int main()
{
	unordered_map<int, int> um;
	auto iter = um.begin();
	auto aInt = 1;

	Func1 func;
	Func2 func2;

	int arr[3] = { 1,2,3 };
	int bInt = { 123 };
	Vector v = { 1.1f, 2.5f };

	vector<int> myV = { 4,1,3,4,2,3,10,124,3 };

	for (auto& element : myV) // auto는 참조 지원
	{
		cout << element << endl;
	}

	tuple<int, int, float, int, string, int> p; // 3가지 이상의 자료형

	string str = "Hello"; // 맨 뒤 비트가 '0'

	return 0;
}