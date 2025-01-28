#include <iostream>

using namespace std;

// 수학함수
// y + f(x)
// 반환자료형 함수이름(매개변수) => 함수 시그니처
// 함수 선언 방법
// void : 공허한

// 포인터 연산자
// *ptr : 간접연산자, 포탈연산자 -> 포인터가 담고있는 주소값으로 포탈 타고 들어감
// &(변수) : 주소연산자 -> 변수가 담겨있는 주소값

// 스택프레임
// - 함수가 호출될 때 매개변수, 반환주소값, 지역변수
// - 매개변수, 반환주소값, 지역변수 (1mb 할당, 스택 오버플로우)
// - 후입선출(LIFO)
// - 컴파일 시간에 크기가 결정
// - 높은 주소 -> 낮은 주소
// ip (Instruction Pointer) : 다음 수행 명령어의 위치
// sp(Stack Pointer) : 현재 스택 top 위치(일종의 cursor)
// bp(Base Pointer) : 스택 상대주소 계산용

// 포인터, 참조 차이
// - 포인터의 주소값 가리키는 값 주소값은 다름
// - 포인터는 별개의 메모리 할당
// - 참조는 동일
// - 참조는 null 가리킬 수 없음, 별명
// - 참조는 할당된 객체 바꿀 수 없음

void HelloWorld()
{
	cout << "Hello World!" << endl;
}


// Call by Value
void AddOne(int num)
{
	// main[반환주소값(), 매개변수(void), 지역변수(aInt(3))], Add[반환주소값(&aInt), 매개변수 (num : 3) 지역변수 ()]
	num++;
	// main[반환주소값(), 매개변수(void), 지역변수(aInt(3))], Add[반환주소값(&aInt), 매개변수 (num : 4) 지역변수 ()]

}

// Call by Address
void AddOne(int* ptr)
{
	// main[반환주소값(), 매개변수(void), 지역변수((0x12)aInt(3))], Add[반환주소값(&aInt), 매개변수 (ptr : 0x12) 지역변수 ()]
	(*ptr)++;
	// main[반환주소값(), 매개변수(void), 지역변수((0x12)aInt(4))], Add[반환주소값(&aInt), 매개변수 (ptr : 0x12) 지역변수 ()]
}


// 같은 이름의 다른 버전 -> 함수 오버로딩
// 다른 버전 : 매개변수의 자료형이나 개수가 다른 것
int Add(int a, int b) {
	int c = a + b;

	// main[반환주소값(), 매개변수(void), 지역변수(aInt(cccccccc))], Add[반환주소값(&aInt), 매개변수 (a 1, b 2) 지역변수 c(3)]
	cout << c << endl;

	return c;
}

int Add(int a, int b, int c)
{
	int d = Add(a, b) + c;

	return d;
}

// 함수 매개변수의 기본인자 -> 매개변수(인자, 파라미터, argument). 무조건 맨 뒤부터
int Add(int a, int b, int c, int d, int e = 1)
{
	int f = Add(a, b, c) + d + e;

	return f;
}

int Add(int a, int b, int c, int d)
{
	int e = a + b + c + d;

	return e;
}


// 재귀호출 : 스택 오버플로우 -> 스택에 더 이상 할당 불가
int Factorial(int num)
{
	if (num == 1)
		return 1;

	return num * Factorial(num - 1);
}


// 메모이제이션 : 이전에 계산한 값을 저장해두고 재사용
int cache[200] = {}; // 전역변수
int Fibonacchi(int num)
{
	if (num == 0 || num == 1)
		return 1;

	int* ref = &cache[num];
	if (*ref != 0)
		return *ref;

	*ref = Fibonacchi(num - 1) + Fibonacchi(num - 2); // cache[2] = 2

	return *ref;
}


int main()
{
	HelloWorld();

	// main[반환주소값(), 매개변수(void), 지역변수(aInt(cccccccc))]

	int aInt = Add(1, 2); // aInt와 c는 다름

	AddOne(aInt);
	// main[반환주소값(), 매개변수(void), 지역변수(aInt(3))]

	AddOne(&aInt);
	// main[반환주소값(), 매개변수(void), 지역변수((0x12)aInt(4))]

	//aInt = Add(1, 2, 3, 4); // 혼동-> 매개변수 4개? 5개?

	aInt = Factorial(5);

	aInt = Fibonacchi(100);

	cout << aInt << endl;

	return 0;
}