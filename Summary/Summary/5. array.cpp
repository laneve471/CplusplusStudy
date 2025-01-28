#include <iostream>

using namespace std;

//1. 상수 선언 방법 3가지
// 선언과 동시에 초기화(Ref)
// #define 매크로
// const
// enum

// 포인터
// (자료형)* (변수이름) : 포인터 선언
// (변수) * (변수) : 곱셈연산자
// *(변수) : 간접연산자
// (자료형)** (변수이름) : 이중포인터

// (변수) & (변수) : 비트 And연산자 -> 다르면 0 같으면 1
// (변수) && (변수) : And연산자
// (자료형)& (변수이름) = (초기화) : Reference 선언
// &(변수) : 주소연산자

// 포인터 연산자
// (ptr + 1) => 자료형에 따라 크기 변경

#define PI 3.141592f

// 정수형 상수
// 열거형
enum PlayerState
{
	IDLE = 5,
	Run = 1,
	FALLING = 2,
	SLEEPING = (1 << 5),
};

void PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void PrintArr(int arr[][3], int size)
{
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; )
	}
}

int main()
{
	//float temp = PI; // 바꿀 수 없음

	// const (자료형) : 상수취급 => 쓰기 불가능
	const int temp = 1;
	PlayerState curState = PlayerState::IDLE;

	int temp2 = 14 & 3;

	// const (자료형)* const : 읽기 전용
	// const 자료형& : 읽기 전용
	const int& ref = temp;
	const int* ptr = &temp;

	int aInt = 1;
	int* ptr2 = &aInt;
	cout << &aInt << endl;
	cout << (ptr2) << endl;
	cout << (ptr2 + 1) << endl;

	int arr[10]; // 정적배열
	// [index] : 임의접근연산자
	// [] [] [] [] []
	// 10 14 18 1C 20
	// 임의접근하는데 걸리는 시간복잡도 (상수)

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	//ptr2 = &arr[0];
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << *(ptr2 + i) << ptr2[i] << arr[i] << endl;
	//}

	PrintArr(ptr2, 10);

	int arr2[2][3] = { (1, 2, 3),
					   (4, 5, 6) };

	PrintArr(&arr2[0][0], ) 으

		return 0;
}