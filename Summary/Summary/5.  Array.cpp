#include <iostream>

using namespace std;

// ��� ���� ��� 3����
// ����� ���ÿ� �ʱ�ȭ(Ref)
// #define ��ũ��
// const
// enum

#define PI 3.141592f

// ������ ���
// ������
enum PlayerState
{
	IDLE = 5,
	Run = 1,
	FALLING = 2,
	SLEEPING = (1 << 5),
};


// ������
// (�ڷ���)* (�����̸�) : ������ ����
// (����) * (����) : ����������
// *(����) : ����������
// (�ڷ���)** (�����̸�) : ����������

// (����) & (����) : ��Ʈ And������ -> �ٸ��� 0 ������ 1
// (����) && (����) : And������
// (�ڷ���)& (�����̸�) = (�ʱ�ȭ) : Reference ����
// &(����) : �ּҿ�����

// ������ ������
// (ptr + 1) => �ڷ����� ���� ũ�� ����


void PrintArr(int* arr, int size) // 1���� �迭
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void PrintArr(int arr[][3], int size) // 2���� �迭
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
	//float temp = PI; // �ٲ� �� ����

	// const (�ڷ���) : ������ => ���� �Ұ���
	const int temp = 1;
	PlayerState curState = PlayerState::IDLE;

	int temp2 = 14 & 3;

	// const (�ڷ���)* const : �б� ����
	// const �ڷ���& : �б� ����
	const int& ref = temp;
	const int* ptr = &temp;

	int aInt = 1;
	int* ptr2 = &aInt;
	cout << &aInt << endl;
	cout << (ptr2) << endl;
	cout << (ptr2 + 1) << endl;

	int arr[10]; // �����迭
	// [index] : �������ٿ�����
	// [] [] [] [] []
	// 10 14 18 1C 20
	// ���������ϴµ� �ɸ��� �ð����⵵ (���)

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	ptr2 = &arr[0];
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << *(ptr2 + i) << ptr2[i] << arr[i] << endl; // ������ ���
	//}

	PrintArr(ptr2, 10);

	int arr2[2][3] = { {1, 2, 3},
					   {4, 5, 6} };

	// int arr2[2][3] = {(1, 2, 3),
	//	 			     (4, 5, 6) };�� ��� ��ǥ ������ ó��
	//								
	//��ǥ ������ : ���� ǥ������ ���� ��, ������ ǥ������ ����� ��ȯ
	//
	//# ���� 1
	//int result = (a = 10, b = 20, c = 30);
	//cout << a << b << c << endl; // ���: 102030
	//cout << result << endl;  // ���: 30 (������ ���� c = 30�� ��ȯ)
	//
	//# ���� 2
	//(x = 5, cout << x << endl, x = 10); // ���: 5
	//cout << x << endl;  // ���: 10


	PrintArr(&arr2[0][0], 6);
	PrintArr(arr2, 2);

	// ���� PrintArr(&arr2[0][0], 2);�� ���
	// 1���� �迭�� �ּҸ� ���� => 1���� �迭�� ó��
	// �����ε��� ���� 1���� ��� �Լ� ȣ��
	// 1, 2�� ���

	return 0;
}