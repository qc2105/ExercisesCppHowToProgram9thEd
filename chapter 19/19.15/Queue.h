#pragma once
#include "List.h"

namespace name19_15
{
	template <class T>
	class Queue : private List<T> 
	{
	public:

		Queue(void)
		{

		}

		bool isEmpty(void) const
		{
			return !list.size();
		}

		bool enqueue(const T& v)
		{
			return list.insertAtBack(v);
		}

		bool dequeue(T& v)
		{
			return list.removeAtFront(v);
		}

		size_t size(void) const
		{
			return list.size();
		}

		const T& front(void)
		{
			return list[0];
		}

		const T& back(void)
		{
			return list[list.size() - 1];
		}

	private:
		List<T> list;
	};
}
