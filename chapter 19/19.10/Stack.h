#pragma once
#include "List.h"

namespace name19_10
{
	template <class T>
	class Stack : private List<T>
	{
	public:

		Stack(void)
		{
		}
		~Stack() {}

		bool push(const T& data)
		{
			return List<T>::insertAtFront(data);
		}

		bool pop(T& data)
		{
			return List<T>::removeAtFront(data);
		}

		const T& top(void) const
		{
			return List<T>::operator[](0);
		}

		bool isEmpty(void) const
		{
			return List<T>::isEmpty();
		}

	};
}
