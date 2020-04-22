#pragma once
#include <iostream>

namespace name19_24 {

	template <class T>
	class List;

	template <class T>
	class Node
	{
		friend class List<T>;
		template <class U>
		friend std::ostream& operator << (std::ostream& out, List<U>& list);
		template <class V>
		friend void swap(Node<V>& a, Node<V>& b);

	public:
		explicit Node(const T& _data) :
			nextPtr(nullptr),
			data(_data)
		{}

		const T& getData(void) const
		{
			return data;
		}

		bool operator > (const Node<T>& b) const
		{
			return this->getData() > b.getData();
		}

	private:
		Node* nextPtr;
		T data;
	};

	template <class T>
	void swap(Node<T>& a, Node<T>& b)
	{
		T temp = a.getData();
		a.data = b.getData();
		b.data = temp;
	}

};