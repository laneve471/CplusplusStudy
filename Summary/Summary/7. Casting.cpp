#include <iostream>
#include <vector>

using namespace std;

//  캐스팅 : 형변환
// int -> char (uncomplete) cuz' bit size

// upcasting
// parent pointer -> son object

// downcasting
// parent object <- son pointer => uncomplete

// 1. static_cast : 논리적으로 통과되면 오케이
//  : 컴파일 중에 통과?
// 
// 2. dynamic case
//  : 상속 구조에서 RTTI가 있으면 통과
//  : RTTI = RunTime Type Information
//  : 실행 중에 통과?
//  : casting fail -> return nullptr
// 
// 3. const cast
//  : 상수 -> 비상수 -> 상수
// 
// 4. reinterpret_cast
//  : c-style 
class Player
{
public:
	// 가상함수를 선언하면 가상함수 테이블이 생긴다
	// 객체의 맨앞 주소에는 가상함수테이블을 가리키는 포인터가 생긴다 => 런타임에 타입이 무엇인지 확인할 수 있다
	// RTTI
	virtual void Hello() { cout << "I'm player " << endl; }

	int _type;
	int _hp;
	int _atk;
};

class Knight : public Player
{
public:
	virtual void Hello() { cout << "I'm knight " << endl; }

	int _type = 1;
	int _stamina = 3;
};
int main()
{
	int aInt = static_cast<int>(1.0f); // 
	float aFloat = 1.0f;
	int* ptr = reinterpret_cast<int*>(&aFloat);
	aInt = 455555;
	char aChar = aInt;

	cout << aInt << endl;
	cout << *ptr << endl;

	Player* p = new Player();
	Player* k = new Knight(); // upcasting

	Knight* k2 = static_cast<Knight*>(new Player()); // c-style casting

	if (k->_type == 1) // dynamic cast랑 사실상 동일
	{
		static_cast<Knight*>(k);
	}

	k2->_stamina = 5; //memory contaminum

	//((Knight*)k)->Hello();

	Knight* dynamicK = dynamic_cast<Knight*>(k);
	if (dynamicK != nullptr)
	{
		dynamicK->Hello();
	}
	else
	{

	}

	const char* str = "Hello"; // rodata
	char* str2 = const_cast<char*>(str);
	//str2[0] = 'K' -> rodata violation


	return 0;
}