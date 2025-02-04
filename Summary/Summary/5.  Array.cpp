#include <iostream>

using namespace std;

// 상수 선언 방법 3가지
// 선언과 동시에 초기화(Ref)
// #define 매크로
// const
// enum

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


void PrintArr(int* arr, int size) // 1차원 배열
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void PrintArr(int arr[][3], int size) // 2차원 배열
{
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cout << arr[y][x] << endl;
		}
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

	ptr2 = &arr[0];
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << *(ptr2 + i) << ptr2[i] << arr[i] << endl; // 동일한 결과
	//}

	PrintArr(ptr2, 10);

	int arr2[2][3] = { {1, 2, 3},
					   {4, 5, 6} };

	// int arr2[2][3] = {(1, 2, 3),
	//	 			     (4, 5, 6) };일 경우 쉼표 연산자 처리
	//								
	//쉼표 연산자 : 왼쪽 표현식을 평가한 후, 오른쪽 표현식의 결과를 반환
	//
	//# 예시 1
	//int result = (a = 10, b = 20, c = 30);
	//cout << a << b << c << endl; // 출력: 102030
	//cout << result << endl;  // 출력: 30 (마지막 값인 c = 30이 반환)
	//
	//# 예시 2
	//(x = 5, cout << x << endl, x = 10); // 출력: 5
	//cout << x << endl;  // 출력: 10


	PrintArr(&arr2[0][0], 6);
	PrintArr(arr2, 2);

	// 만약 PrintArr(&arr2[0][0], 2);일 경우
	// 1차원 배열의 주소를 전달 => 1차원 배열로 처리
	// 오버로딩에 의해 1차원 출력 함수 호출
	// 1, 2만 출력

	return 0;
}