#include <iostream>

using namespace std;

// 문자열 특징
// - 맨 뒷 비트가 0으로 끝나야 문자열이 끝났다고 판단
// - Escape Sequence
// -- '\0' : 0
// -- '\t' : tap
// -- '\'' : '
// -- '\n' : 다음 줄

// 문자열의 길이
unsigned __int64 Length(const char* str)
{
	unsigned __int64 count = 0;
	for (str; *str != '\0'; str++)
	{
		count++;
	}
	return count;
}

unsigned __int64 Length(const char* str)
{
	unsigned __int64 count = 0;
	for (int i = 0; ; i++)
	{
		if (str[i] == '\0')
			break;
		count++;
	}
	return count;
}

// 문자열 비교
bool Compare(const char* str1, const char* str2)
{
	bool compare = true;

	while (*str1 != '\0' && *str2 != '\0' && compare)
	{
		if (*str1 != *str2)
		{
			compare = false;
		}
		str1++;
		str2++;
	}
	return compare;
}
/*
bool Compare(const)
{
	int length1 = Length(str1);
	if (length1 != Length(str2))
		return false;
}
*/

int main()
{
	const char* str1 = "Hello"; // \0 숨어있음
	const char* str2 = "Helo";
	//char str2[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	cout << str1 << endl;
	cout << str2 << endl;

	cout << Length(str1) << endl;
	cout << Compare(str1, str2) << endl;
}