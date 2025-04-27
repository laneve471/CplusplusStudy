#include <iostream>
#include <list>
#include <queue>

using namespace std;

// queue : 선입선출 -> First Input First Out : FIFO

template <typename T, typename Container = list<T>>
class Queue
{
public:
	bool empty() { return l.empty(); }

	T front() { return l.front(); }

	void push(T value) { l.push_back(value); }

	T pop() { l.pop_front(); }

private:
	Container l;
};

int main()
{
	Queue<int> q;

	q.push(10);
	q.push(7);
	q.push(15);
	q.push(1);
	q.push(3);

	while (true)
	{
		if (q.empty() == true)
			break;

		cout << q.front() << endl;
		q.pop();
	}
}