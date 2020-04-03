#pragma once
#include <iostream>

template <class T>
class List;

template <class T>
class Node
{
	friend class List<T>;
	template <class U>
	friend std::ostream& operator << (std::ostream& out, List<U>& list);

public:
	Node(const T& _data) :
		nextPtr(nullptr),
		data(_data)
	{}

	const T& getData(void) const
	{
		return data;
	}

private:
	Node* nextPtr;
	T data;
};