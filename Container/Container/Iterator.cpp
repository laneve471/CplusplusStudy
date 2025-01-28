#include <iostream>
#include <vector>
#include <list>
#include "List.h"
#include "Vector.h"

using namespace std;

// iterator : 반복자(순회자)

int main()
{
	vector<int> v = { 1,2,3,4,5,6 };

	// vector는 임의접근연산자로 순회가 가능. list는 불가
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	// vector를 iter로 순회하는 방법
	vector<int>::iterator iter;
	iter = v.begin();
	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	cout << "------------" << endl;
	

	return 0;
}