#include <iostream>

using namespace std;

//ref
// (자료형)& (Ref 이름) = (초기화);
// - C++ 관점 : 해당 변수의 별명
// - 어셈블리어 : 포인터랑 
// - 크기 : 32비트(4) 64비트 (8)

// ptr, ref 차이
// 1. 포인터는 중간에 대상 변경 가능 / Ref는 중간에 대상 변경 불가
// 2. 포인터는 nullptr를 저장할 수 있다 / Ref는 없는 값을 참조할 수 없다
// 3. 포인터는 초기화를 하지 않아도 된다 / Ref는 무조건 초기화

// 상수 선언 3가지 공부

// Call by value
// 매개변수 value만 읽기, 수정 가능하다
// 원본 수정 불가. 원본 읽기(복사) 가능
/*
void AddOne(int num)
{
	num++;
}
*/

// Call by address
// 매개변수 ptr에 타고 들어가서 읽기 수정 가능
// 원본 수정 가능
// 쓰기 어려움(메모리 오염)
void AddOne(int* const ptr) // 0x12
{
	// ptr = (int*) 0x12341234 -> 메모리 오염

	(*ptr)++;
}

// Call by reference
// 매개변수 ref(별명)에 가서 읽기 수정 가능
// 원본을 수정할 수 있다
// -> 쓰기 쉽다
void AddOne(int& ref)
{
	ref++;
}

int main()
{
	int aInt = 1;
	int bInt = 2;

	int* ptr = &aInt; //0xcccccccc
	ptr = NULL;

	int& ref = aInt;
	ref = bInt; // aInt에 bInt 값 할당

	cout << aInt << endl; // 2 출력
	cout << ref << endl;
	cout << bInt << endl;

	aInt = 1;
	AddOne(&aInt); // (0x12)aInt
	AddOne(aInt);

	cout << aInt << endl;

	return 0;
}