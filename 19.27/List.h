#pragma once
#include "Node.h"
#include <stdexcept>
#include <iostream>

namespace name19_27 {

	template <class T>
	class List
	{
		template <class U>
		friend std::ostream& operator << (std::ostream& out, List<U>& list);
		template <class V>
		friend std::istream& operator >> (std::istream& in, List<V>& list);

	public:
		List(void) :
			headPtr(nullptr),
			accessedPtr(nullptr),
			currentPosition(0),
			nSize(0)
		{}

		//copy constructor
		List(const List<T>& b)
		{
			headPtr = accessedPtr = nullptr;
			currentPosition = 0;
			nSize = 0;

			Node<T>* currentPtr = b.headPtr;
			while (currentPtr != nullptr)
			{
				this->insertAtBack(currentPtr->getData());
				currentPtr = currentPtr->nextPtr;
			}
		}

		~List()
		{
			Node<T>* tempPtr = nullptr;
			Node<T>* currentPtr = headPtr;

			while (currentPtr != nullptr)
			{
				tempPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
				delete tempPtr;
				--nSize;
			}
			headPtr = accessedPtr = nullptr;
			currentPosition = 0;
		}

		size_t size(void) const
		{
			return nSize;
		}

		void clear(void)
		{
			while (nSize != 0)
			{
				T data;
				removeAtBack(data);
			}
		}

		bool isEmpty(void) const
		{
			return !nSize;
		}

		bool operator!=(const List<T>& b) const
		{
			return !operator==(b);
		}

		bool operator==(const List<T>& b) const
		{
			if (this->size() != b.size())
			{
				return false;
			}
			Node<T>* ptr1 = nullptr;
			Node<T>* ptr2 = nullptr;
			for (ptr1 = this->headPtr, ptr2 = b.headPtr; ptr1 != nullptr; ptr1 = ptr1->nextPtr, ptr2 = ptr2->nextPtr)
			{
				if (ptr1->data != ptr2->data)
				{
					return false;
				}
			}

			return true;
		}

		bool insertAtFront(const T& data)
		{
			try
			{
				Node<T>* newNode = createNode(data);

				if (!isEmpty())
				{
					newNode->nextPtr = headPtr;
					headPtr = newNode;
				}
				else
				{
					headPtr = newNode;
				}
				currentPosition = 0;
				accessedPtr = headPtr;
				++nSize;

				return true;
			}
			catch (...)
			{
				std::cerr << "Node creation failed.\n";
				return false;
			}

			// should never reach here.
			return false;
		}

		bool removeAtFront(T& data)
		{
			if (isEmpty())
			{
				return false;
			}

			data = headPtr->data;
			if (nSize == 1)
			{
				delete headPtr;
				headPtr = nullptr;
			}
			else
			{
				Node<T>* tempPtr = headPtr;
				headPtr = headPtr->nextPtr;
				delete tempPtr;
			}
			--nSize;
			currentPosition = 0;
			accessedPtr = headPtr;

			return true;
		}

		bool insertAtBack(const T& data)
		{
			try
			{
				Node<T>* newNode = createNode(data);

				if (!isEmpty())
				{
					Node<T>* currentPtr = headPtr;
					while (currentPtr->nextPtr != nullptr)
					{
						currentPtr = currentPtr->nextPtr;
					}
					currentPtr->nextPtr = newNode;
				}
				else
				{
					headPtr = newNode;
				}
				currentPosition = nSize;
				accessedPtr = newNode;
				++nSize;

				return true;
			}
			catch (...)
			{
				std::cerr << "Node creation failed.\n";
				return false;
			}

			// should never reach here.
			return false;
		}

		bool removeAtBack(T& data)
		{
			if (isEmpty())
			{
				return false;
			}

			Node<T>* currentPtr = headPtr;
			while (currentPtr->nextPtr != nullptr)
			{
				currentPtr = currentPtr->nextPtr;
			}

			data = currentPtr->data;
			if (nSize == 1)
			{
				delete headPtr;
				headPtr = nullptr;
				accessedPtr = nullptr;
			}
			else
			{
				Node<T>* currentPtr = headPtr;
				while (currentPtr->nextPtr->nextPtr != nullptr)
				{
					currentPtr = currentPtr->nextPtr;
				}

				Node<T>* tempPtr = currentPtr->nextPtr;
				currentPtr->nextPtr = nullptr;
				delete tempPtr;
				tempPtr = nullptr;

				accessedPtr = currentPtr;

			}
			--nSize;
			currentPosition = nSize - 1;
			
			return true;
		}

		bool insertAfterValue(const T& value, const T& data)
		{
			try
			{
				Node<T>* currentPtr = headPtr;
				currentPosition = 0;
				while (currentPtr != nullptr)
				{
					++currentPosition;

					if (value == currentPtr->data)
					{
						Node<T>* newNode = createNode(data);
						newNode->nextPtr = currentPtr->nextPtr;
						currentPtr->nextPtr = newNode;
						++nSize;
						
						++currentPosition;
						accessedPtr = newNode;
						return true;
					}

					currentPtr = currentPtr->nextPtr;
				}

				return false; // no such value 
			}
			catch (...)
			{
				std::cerr << "Node insertion failed.\n";
				return false;
			}
			return false;
		}

		bool removeAfterValue(const T& value, T& data)
		{
			if (isEmpty())
			{
				return false;
			}

			Node<T>* currentPtr = headPtr;
			currentPosition = 0;
			while (currentPtr != nullptr)
			{
				++currentPosition;
				accessedPtr = currentPtr;
				if (currentPtr->data == value)
				{
					Node<T>* toBeDeleted = currentPtr->nextPtr;
					if (toBeDeleted == nullptr)	// currentPtr is tailPtr;
					{
						return false;
					}
					data = toBeDeleted->data;
					currentPtr->nextPtr = toBeDeleted->nextPtr;
					if (toBeDeleted->nextPtr == nullptr)
					{
						currentPosition = nSize - 1;
						accessedPtr = currentPtr;
					}
					delete toBeDeleted;
					accessedPtr = currentPtr->nextPtr;
					--nSize;

					return true;
				}
				currentPtr = currentPtr->nextPtr;
			}

			return false;
		}

		bool insertAfterPosition(const size_t pos, const T& data)
		{
			if (pos >= size())
			{
				return false;
			}

			try
			{
				Node<T>* currentPtr = headPtr;
				currentPosition = 0;
				while (currentPtr != nullptr)
				{
					if (currentPosition == pos)
					{
						Node<T>* newNode = createNode(data);
						newNode->nextPtr = currentPtr->nextPtr;
						currentPtr->nextPtr = newNode;
						++nSize;
					
						++currentPosition;
						accessedPtr = newNode;
						return true;
					}

					++currentPosition;
					currentPtr = currentPtr->nextPtr;
				}

				return false; // no such position , shouldn't happen
			}
			catch (...)
			{
				std::cerr << "Node insertion failed.\n";
				return false;
			}
			return false;
		}

		bool removeAfterPosition(const size_t pos, T& data)
		{
			if (pos >= size())
			{
				return false;
			}
			if (isEmpty())
			{
				return false;
			}

			Node<T>* currentPtr = headPtr;
			currentPosition = 0;
			while (currentPtr != nullptr)
			{
				accessedPtr = currentPtr;
				if (pos == currentPosition)
				{
					Node<T>* toBeDeleted = currentPtr->nextPtr;
					if (toBeDeleted == nullptr)	// currentPtr is tailPtr;
					{
						return false;
					}
					data = toBeDeleted->data;
					currentPtr->nextPtr = toBeDeleted->nextPtr;
					++currentPosition;
					if (toBeDeleted->nextPtr == nullptr)
					{
						currentPosition = nSize - 1;
						accessedPtr = currentPtr;
					}
					delete toBeDeleted;
					accessedPtr = currentPtr->nextPtr;
					--nSize;

					return true;
				}

				++currentPosition;
				currentPtr = currentPtr->nextPtr;
			}

			return false;
		}

		bool insertAtPosition(const size_t pos, const T& data)
		{
			if (pos >= size())
			{
				return false;
			}
			
			if (pos == 0)
			{
				return insertAtFront(data);
			}
			else
			{
				return insertAfterPosition(pos - 1, data);
			}

			return false; // this shouldn't happen
		}

		bool removeAtPosition(const size_t pos, T& data)
		{
			if (pos >= size())
			{
				return false;
			}
			if (isEmpty())
			{
				return false;
			}

			if (pos == 0)
			{
				return removeAtFront(data);
			}
			else
			{
				return removeAfterPosition(pos - 1, data);
			}

			return false; // this shouldn't happen
		}

		const T& operator[](const size_t i)
		{
			if (i >= size())
			{
				throw std::out_of_range("subcript out of range\n");
			}

			Node<T>* currentPtr = nullptr;

			if (i >= currentPosition)
			{
				currentPtr = accessedPtr;
				for (size_t idx = 0; idx < i - currentPosition; ++idx)
				{
					currentPtr = currentPtr->nextPtr;
				}
			}
			else
			{
				currentPtr = headPtr;
				for (size_t idx = 0; idx < i; ++idx)
				{
					currentPtr = currentPtr->nextPtr;
				}
			}

			accessedPtr = currentPtr;
			currentPosition = i;
			return currentPtr->getData();
		}

		void printStr(void) const
		{
			if (isEmpty())
			{
				std::cout << "List is empty\n";
			}
			Node<T>* currentPtr = headPtr;
			while (currentPtr != nullptr)
			{
				std::cout << currentPtr->data;
				currentPtr = currentPtr->nextPtr;
			}
			std::cout << std::endl;
		}

		void sort(void)
		{
			Node<T>* currentPtr = nullptr;
			for (currentPtr = headPtr; currentPtr != nullptr; currentPtr = currentPtr->nextPtr)
			{
				for (Node<T>* temp = currentPtr->nextPtr; temp != nullptr; temp = temp->nextPtr)
				{
					if (*currentPtr > (*temp))
					{
						swap(*currentPtr, *temp);
					}
				}
			}
		}

	private:
		Node<T>* headPtr;
		Node<T>* accessedPtr;
		size_t currentPosition;
		size_t nSize;

		Node<T>* createNode(const T& data)
		{
			Node<T>* newNode = new Node<T>(data);
			newNode->nextPtr = nullptr;
			return newNode;
		}
	};

	template <class T>
	std::ostream& operator << (std::ostream& out, List<T>& list)
	{
		Node<T>* currentPtr = list.headPtr;
		while (currentPtr != nullptr)
		{
			out << currentPtr->data << ' ';
			currentPtr = currentPtr->nextPtr;
		}
		out << std::endl;

		return out;
	}

	template<class V>
	std::istream& operator>>(std::istream& in, List<V>& list)
	{
		V temp;
		while (in >> temp)
		{
			list.insertAtBack(temp);
		}

		return in;
	}

};