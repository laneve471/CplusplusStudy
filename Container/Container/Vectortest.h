#pragma once

template <typename T>
class Vector
{
public:
	Vector()
		: _size(0), _capacity(0)
	{
		_data = new T[_capacity];
	}

	~Vector()
	{
		clear();
	}

	void reserve(unsigned __int64 capacity)
	{
		if (_capacity < capacity)
		{
			T* newData = new T[capacity];
			for (unsigned __int64 i = 0; i < _size; i++)
				newData[i] = _data[i];
			delete[] _data;
			_data = newData;
		}
		_capacity = capacity;
	}

	void push_back(const T& data)
	{
		if (_capacity <= _size)
		{
			_capacity = static_cast <unsigned __int64>(_capacity * 1.5);
			reserve(_capacity);
		}
		_data[_size] = data;
		_size++;
	}

	void pop_back()
	{
		if (_size == 0)
		{
			int* error = (int*)0xDEADBEEF;
			*(error) = 1;
			//ERROR
		}
		_size--;
		T* newData = new T[_capacity];
		for (unsigned __int64 i = 0; i < _size; i++)
			newData[i] = _data[i];
		delete[] _data;
		_data = newData;
	}

	T operator[](unsigned __int64 index)
	{
		if (index >= _size)
		{
			int* error = (int*)0xDEADBEEF;
			*(error) = 1;
			//ERROR
		}

		return _data[index];
	}

	void clear()
	{
		delete[] _data;
		_data = nullptr;
		_size = 0;
		_capacity = 0;
	}

	void insert(T value, unsigned __int64 index)
	{
		if (index >= _size)
		{
			int* error = (int*)0xDEADBEEF;
			*(error) = 1;
			//ERROR
		}

		_size++;
		if (_capacity < _size)
		{
			_capacity = static_cast <unsigned __int64>(_capacity * 1.5);
			reserve(_capacity);
		}

		for (unsigned __int64 i = _size - 1; i > index; i--)
			_data[i] = _data[i-1];
		_data[index] = value;
	}

	unsigned __int64 size() { return _size; }
	unsigned __int64 capacity() { return _capacity; }

private:
	unsigned __int64 _capacity;
	unsigned __int64 _size;
	T* _data;
};