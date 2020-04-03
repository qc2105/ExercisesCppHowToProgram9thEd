#pragma once
#include "Node.h"
#include <stdexcept>
#include <iostream>

template <class T>
class List
{
	template <class U>
	friend std::ostream& operator << (std::ostream& out, List<U>& list);
	
public:
	List(void) :
		headPtr(nullptr),
		tailPtr(nullptr),
		accessPtr(nullptr),
		currentPosition(0),
		nSize(0)
	{}

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
		headPtr = tailPtr = nullptr;
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
			accessPtr = headPtr;
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
		accessPtr = headPtr;

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
			accessPtr = tailPtr;
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
		accessPtr = tailPtr;

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
			currentPtr = accessPtr;
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
		
		accessPtr = currentPtr;
		currentPosition = i;
		return currentPtr->getData();
	}

	void printStr(void)
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

private:
	Node<T>* headPtr;
	Node<T>* tailPtr;
	Node<T>* accessPtr;
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