#include <iostream>
#include <vector>

using namespace std;

class Player
{
	int data[100]; // 400바이트
};

int main()
{
	vector<int> v;
	cout << "v의 용량 : " << v.capacity() << "    v의 크기 : " << v.size() << endl;
	vector<Player> p;
	p.reserve(10); // => 4000바이트 예약

	vector<Player*> p2;
	p2.reserve(10); // => 40바이트
	p2.push_back(new Player());
	

	v.reserve(1000);
	// v.resize(1000, -1);

	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
		cout << "v의 용량 : " << v.capacity() << "    v의 크기 : " << v.size() << endl;
	}

	// 벡터 초기화
	vector<int> a(2, 0); // 크기 2를 0으로 초기화
	vector<int> b = { 2, 0 };
	for (int n : a) { cout << n << " "; } // 0 0
	for (int n : b) { cout << n << " "; } // 2 0


	// 범위 생성자
	vector<int> v1 = { 10, 20, 30, 40, 50 };

	// v1의 요소들을 벡터로 복사
	vector<int> v2(v1.begin() + 1, v1.begin() + 3);

	for (int v : v2) {cout << v << " ";} // 20 30
	// 왜 20 30인가?
	// new_vector(first_iterator, last_iterator);에서 [first, last)
	// first는 포함하고 last는 포함하지 않는 범위
	// 따라서 40은 포함되지 않음

	return 0;
}