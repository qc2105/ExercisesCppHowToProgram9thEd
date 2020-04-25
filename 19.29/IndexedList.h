#pragma once
#include "List.h"
#include <exception>

namespace name19_29
{
	template <class T>
	class IndexedList
	{
	public:
		IndexedList(size_t _indexSize) :
			indexSize(_indexSize)
		{
			try {
				indexPtr = new List<T>[_indexSize]();
			}
			catch (const std::exception& e)
			{
				throw e;
			}
		}

		virtual ~IndexedList()
		{
			delete[] indexPtr;
		}

		bool insertInIndexedList(const T& data)
		{
			size_t index = getIndex(data);
			return (indexPtr + index)->insertAtBack(data);
		}

		bool deleteFromIndexedList(const T& data)
		{
			size_t index = getIndex(data);
			T v;
			for (size_t i = 0; i < (indexPtr + index)->size(); ++i)
			{
				if ((*(indexPtr + index))[i] == data)
				{
					return (indexPtr + index)->removeAtPosition(i, v);
				}
			}

			return false;
		}

		Node<T>* searchIndexedList(const T& data)
		{
			size_t index = getIndex(data);
			
			return (indexPtr + index)->searchList(data);
		}

	private:
		virtual size_t getIndex(const T& data) = 0;
		List<T>* indexPtr;
		size_t indexSize;
	};
}