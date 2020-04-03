#pragma once

template <class T>
class List;

template <class T>
class Node
{
	friend class List<T>;
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