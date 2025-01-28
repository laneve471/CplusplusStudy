#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
void PrintVector(vector<int> vec)
{
	vector<int>::iterator iter1 = vec.begin();
	for (iter1; iter1 != vec.end(); iter1++)
		cout << *iter1 << " ";
	cout << endl;
}

bool Find_if(int element)
{
	if (element > 25)
		return true;
	return false;
}

int Transform_Multiply(int i) { return i * 3; }

int main()
{
	vector <int> v = { 31, 23, 3, 2, 1, 3, 12, 15, 19 };
	// 1. v에서 23이 있는 원소의 자리(iter)를 찾기
	vector<int>::iterator iter;
	for (iter = v.begin() ; iter != v.end(); iter++)
	{
		if (*iter == 23)
			break;
	}
	cout << *iter << endl;

	iter = std::find(v.begin(), v.end(), 23);
	if (iter != v.end())
		cout << *iter << endl;

	// 2. v에서 25보다 큰 수가 있다면 그 자리 찾기
	iter = v.begin();
	for (iter; iter != v.end(); iter++)
	{
		if (*iter > 25)
			break;
	}
	cout << *iter << endl;

	iter = std::find_if(v.begin(), v.end(), &Find_if);


	struct Find_If_Functor
	{
		bool operator()(int element)
		{
			if (element > compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	Find_If_Functor functor1;
	functor1.compareNum = 25;
	iter = std::find_if(v.begin(), v.end(), functor1);

	functor1.compareNum = 27;
	iter = std::find_if(v.begin(), v.end(), functor1);

	cout << *iter << endl;
 
	// 3. v에서 3의 개수가 몇 개인지
	int myCount1 = std::count(v.begin(), v.end(), 3);
	cout << myCount1 << endl;

	
	// 4. v에서 10보다 큰 수는 몇 개인지
	struct Count_If_Functor
	{
		bool operator()(int element)
		{
			if (element > compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	Count_If_Functor functor2;
	functor2.compareNum = 10;
	int myCount2 = std::count_if(v.begin(), v.end(), functor2);
	cout << myCount2 << endl;
	
	// 5. v에서 모든 수가 50보다 작은지
	struct All_Of_Functor
	{
		bool operator()(int element)
		{
			if (element < compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	All_Of_Functor functor3;
	functor3.compareNum = 50;
	bool myCount3 = std::all_of(v.begin(), v.end(), functor3);
	cout << myCount3 << endl;

	// 6. v에서 하나라도 20보다 크고 30보다 작은 수가 있는지

	struct Any_Of_Functor
	{
		bool operator()(int element)
		{
			if (compareNum1 < element && element < compareNum2)
				return true;
			return false;
		}

		int compareNum1;
		int compareNum2;
	};
	Any_Of_Functor functor4;
	functor4.compareNum1 = 20;
	functor4.compareNum2 = 30;
	bool myCount4 = std::any_of(v.begin(), v.end(), functor4);
	cout << myCount4 << endl;
	
	// 7. v의 배열을 거꾸로 만들어주세요
	std::reverse(v.begin(), v.end());
	PrintVector(v);

	// 8. 각 v의 원소에 3을 곱해주세요
	std::transform(v.begin(), v.end(), v.begin(), Transform_Multiply);
	PrintVector(v);

	// 9. v를 정렬해주세요
	std::sort(v.begin(), v.end());
	PrintVector(v);

	// 10. v에서 중복된 원소가 있다면 삭제해주세요
	std::unique(v.begin(), v.end());
	PrintVector(v);
	
	// 11. v에서 45인 원소가 있다면 삭제
	std::remove_copy(v.begin(), v.end(), v.begin(), 45);

	// 12. v에서 20보다 작은 원소를 삭제
	struct All_Of_Functor
	{
		bool operator()(int element)
		{
			if (element < compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	All_Of_Functor functor3;
	functor3.compareNum = 50;
	bool myCount3 = std::all_of(v.begin(), v.end(), functor3);
	cout << myCount3 << endl;
	return 0;
}