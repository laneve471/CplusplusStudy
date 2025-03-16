#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// stack : 선입후출 -> Last Out First In (LIFO)

template <typename T, typename Container = vector<T>>
class Stack
{
public:
	bool empty() { return v.empty(); }

	T top() { return v.back(); }

	void push(T value) { v.push_back(value); }

	void pop() { v.pop_back(); }

private:
	Container v;
};

int main()
{
	Stack<int> s;

	s.push(10);
	s.push(1);
	s.push(15);
	s.push(6);
	s.push(100);

	while (true)
	{
		if (s.empty() == true)break;

		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}