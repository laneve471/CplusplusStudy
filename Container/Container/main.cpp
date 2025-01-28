#include <iostream>
#include <list>
#include <vector>

using namespace std;

#include "List.h"
#include "Vector.h"

int main()
{
	List<int> myList;

	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.push_back(4);
	myList.push_front(5);
	myList.push_front(6);
	myList.push_front(7);
	myList.push_front(8);
	// 8 7 6 5 1 2 3 4

	myList.pop_front();
	myList.pop_back();

	myList.insert(4, 2);

	for (int i = 0; i < myList.size(); i++)
	{
		cout << myList[i] << endl;
	}

	cout << "-----------" << endl;

	vector<int> myV;
	myV.push_back(1);
	myV.push_back(2);
	myV.push_back(3);
	myV.push_back(4);
	myV.push_back(5);

	// myV.insert(10, 3);

	for (int i = 0; i < myV.size(); i++)
	{
		cout << myV[i] << endl;
	}

	myV.clear(); // Clear한다고 Heap이 해제되지는 않음
	cout << myV.capacity() << endl;

	vector<int>();
	vector<int>().swap(myV); // 임시객체와 스왑해서 실제 데이터 날림

	

	return 0;
}