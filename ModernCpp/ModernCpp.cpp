#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

// ModernCPP
// C++ 11
// - auto
//  = ������ �ʱ�ȭ
//  = �����ϸ� ������ ������

// - using
//  = ���ø����� ȣȯ ����
// 
// - �߰�ȣ �ʱ�ȭ, �ʱ�ȭ ����Ʈ
// 
// - friend, default
//
// - ���� ��� for��
//
// - tuple
//
// - string
//
// - deque
// 
// - ����
// - std::move
// - ����Ʈ������


//void(*func2)(void); // ����
typedef void(*Func1)(void); // Ÿ�� ����
using Func2 = void(*)(void);

struct Vector
{
	Vector() = default; // �������

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

	for (auto& element : myV) // auto�� ���� ����
	{
		cout << element << endl;
	}

	tuple<int, int, float, int, string, int> p; // 3���� �̻��� �ڷ���

	string str = "Hello"; // �� �� ��Ʈ�� '0'

	return 0;
}