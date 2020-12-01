#pragma once
#include "Node.h"
#include <stdexcept>
#include <iostream>

namespace name19_15 {

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
			tailPtr(nullptr),
			accessedPtr(nullptr),
			currentPosition(0),
			nSize(0)
		{}

		//copy constructor
		List(const List<T>& b)
		{
			headPtr = tailPtr = accessedPtr = nullptr;
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
			headPtr = tailPtr = accessedPtr = nullptr;
			currentPosition = 0;
		}

		size_t size(void) const
		{
			return nSize;
		}

		bool isEmpty(void) const
		{
			return !nSize;
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
					tailPtr = newNode;
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
			if (headPtr == tailPtr)
			{
				Node<T>* tempPtr = headPtr;
				headPtr = tailPtr = nullptr;
				delete tempPtr;
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
					tailPtr->nextPtr = newNode;
					tailPtr = newNode;
				}
				else
				{
					headPtr = newNode;
					tailPtr = newNode;
				}
				currentPosition = nSize;
				accessedPtr = tailPtr;
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

			data = tailPtr->data;
			if (headPtr == tailPtr)
			{
				Node<T>* tempPtr = tailPtr;
				headPtr = tailPtr = nullptr;
				delete tempPtr;
			}
			else
			{
				Node<T>* tempPtr = tailPtr;
				Node<T>* currentPtr = headPtr;
				while (currentPtr->nextPtr != tailPtr)
				{
					currentPtr = currentPtr->nextPtr;
				}

				tailPtr = currentPtr;
				currentPtr->nextPtr = nullptr;
				delete tempPtr;
			}
			--nSize;
			currentPosition = nSize - 1;
			accessedPtr = tailPtr;

			return true;
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
		Node<T>* tailPtr;
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
		out << "Size: " << list.size() << ",\t";
		out << "Elements: ";

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