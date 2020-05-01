#pragma once
#include "Node.h"
#include <stdexcept>
#include <iostream>

namespace name20_5 {

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
			~List();
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

		bool operator!=(const List<T>& b) const
		{
			return !operator==(b);
		}

		bool operator=(const List<T>& b)
		{
			~List();
			headPtr = tailPtr = accessedPtr = nullptr;
			currentPosition = 0;
			nSize = 0;

			bool ret = false;

			Node<T>* currentPtr = b.headPtr;
			while (currentPtr != nullptr)
			{
				ret = this->insertAtBack(currentPtr->getData());
				currentPtr = currentPtr->nextPtr;
				if (!ret)
				{
					return false;
				}
			}

			return true;
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
						if (newNode->nextPtr == nullptr)
						{
							tailPtr = newNode;
						}
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
						tailPtr = currentPtr;
						currentPosition = nSize - 1;
						accessedPtr = tailPtr;
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
						if (newNode->nextPtr == nullptr)
						{
							tailPtr = newNode;
						}
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
						tailPtr = currentPtr;
						currentPosition = nSize - 1;
						accessedPtr = tailPtr;
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

		Node<T>* searchList(const T& data)
		{
			Node<T>* resultPtr = nullptr;

			Node<T>* currentPtr = headPtr;
			while (currentPtr != nullptr)
			{
				if (currentPtr->data == data)
				{
					resultPtr = currentPtr;
					break;
				}
				currentPtr = currentPtr->nextPtr;
			}

			return resultPtr;
		}

		T& operator[](const size_t i)
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
			return currentPtr->data;
		}

		Node<T>& getNode(const size_t i)
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
			return *currentPtr;
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

		// selection sort
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

		// Bubble sort
		void bSort(void)
		{
			for (size_t l = 0; l < size(); ++l)
			{
				for (size_t i = 0, j = i + 1; i < size() - 1; ++i, ++j)
				{
					if ((*this)[i] > (*this)[j])
					{
						swap(getNode(i), getNode(j));
					}
				}
			}
		}

		// Merge sort
		void mSort(void)
		{
			mergeSort(0, size()-1);
		}

	private:
		Node<T>* headPtr;
		Node<T>* tailPtr;
		Node<T>* accessedPtr;
		size_t currentPosition;
		size_t nSize;

		void mergeSort(size_t low, size_t high)
		{
			if (high - low >= 1)
			{
				size_t middle1 = (low + high) / 2;
				size_t middle2 = middle1 + 1;

				mergeSort(low, middle1);
				mergeSort(middle2, high);

				merge(low, middle1, middle2, high);
			}
		}

		void merge(size_t low, size_t middle1, size_t middle2, size_t high)
		{
			List<T> tempList;

			size_t leftIndex = low;
			size_t rightIndex = middle2;

			while (leftIndex <= middle1 && rightIndex <= high)
			{
				if (this->operator[](leftIndex) < this->operator[](rightIndex))
				{
					tempList.insertAtBack(this->operator[](leftIndex));
					++leftIndex;
				}
				else
				{
					tempList.insertAtBack(this->operator[](rightIndex));
					++rightIndex;
				}
			}

			// left is over, merge all in right
			if (leftIndex > middle1)
			{
				while (rightIndex <= high)
				{
					tempList.insertAtBack(this->operator[](rightIndex));
					++rightIndex;
				}
			}
			else // right is over, merge all in left
			{
				while (leftIndex <= middle1)
				{
					tempList.insertAtBack(this->operator[](leftIndex));
					++leftIndex;
				}
			}

			for (size_t i = low, j = 0; i <=high && j < tempList.size(); ++i, ++j)
			{
				this->operator[](i) = tempList[j];
			}
		}

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