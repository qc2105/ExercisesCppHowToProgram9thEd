#pragma once
#include <iostream>
#include <iomanip>
#include <stdexcept>

template <class T>
class DoubleSubscriptedArray
{
	template <class T1>
	friend std::ostream & operator<< (std::ostream &out, const DoubleSubscriptedArray<T1> &right);
	template <class T1>
	friend std::istream & operator>> (std::istream &in, DoubleSubscriptedArray<T1> &right);
public:
	DoubleSubscriptedArray(int row = 3, int column = 3);
	DoubleSubscriptedArray(const DoubleSubscriptedArray<T> &right);
	~DoubleSubscriptedArray();

	size_t getSize(void) const;
	void getShape(int &row, int &column) const;
	T& operator() (int row, int column);
	T operator() (int row, int column) const;
	bool operator== (const DoubleSubscriptedArray<T> & right) const;
	bool operator!= (const DoubleSubscriptedArray<T> & right) const
	{
		return !operator==(right);
	}
	DoubleSubscriptedArray<T> & operator= (const DoubleSubscriptedArray<T> & right);	

private:
	int nRows;		// rows of the array.
	int nColumns;	// columns of the array.
	T *ptrData;		// a pointer to the internal data array.	
};

template<class T>
inline DoubleSubscriptedArray<T>::DoubleSubscriptedArray(int row, int column)
	:nRows(row > 0 ? row : 
		throw std::invalid_argument("Array row size must be greater than 0")),
	nColumns(column > 0 ? column:
		throw std::invalid_argument("Array column size must be greater than 0")),
	ptrData(new T[nRows*nColumns]())
{
}

//copy constructor
template<class T>
inline DoubleSubscriptedArray<T>::DoubleSubscriptedArray(const DoubleSubscriptedArray<T>& right)
	:nRows(right.nRows),
	nColumns(right.nColumns),
	ptrData(new T[right.nRows * right.nColumns]())
{
	this->operator=(right);
}

template<class T>
inline DoubleSubscriptedArray<T>::~DoubleSubscriptedArray()
{
	delete[] ptrData;
	ptrData = nullptr;
}

template<class T>
inline size_t DoubleSubscriptedArray<T>::getSize(void) const
{
	return nRows * nColumns;
}

template<class T>
inline void DoubleSubscriptedArray<T>::getShape(int & row, int & column) const
{
	row = nRows;
	column = nColumns;
}

template<class T>
inline T & DoubleSubscriptedArray<T>::operator()(int row, int column)
{
	if (row >= nRows || column >= nColumns)
	{
		throw std::invalid_argument("invalid row or column\n");
	}
	T* ptr = ptrData;
	ptr += nColumns * row;	// move to the row
	ptr += column;			// move to the column;
	
	return *ptr;
}

template<class T>
inline T DoubleSubscriptedArray<T>::operator()(int row, int column) const
{
	T* ptr = ptrData;
	ptr += nColumns * row;	// move to the row
	ptr += column;			// move to the column;

	return *ptr;
}

template<class T>
inline bool DoubleSubscriptedArray<T>::operator==(const DoubleSubscriptedArray<T> & right) const
{
	if (getSize() != right.getSize())
	{
		return false;
	}

	for (size_t i = 0; i < getSize(); i++)
	{
		if (ptrData[i] != (right.ptrData)[i])
		{
			return false;
		}
	}

	return true;
}

template<class T>
inline DoubleSubscriptedArray<T> & DoubleSubscriptedArray<T>::operator=(const DoubleSubscriptedArray<T> & right)
{
	if (this == &right)	// self-assignment
	{
		return *this;
	}
	
	if (getSize() != right.getSize())
	{
		delete[] ptrData;
		ptrData = nullptr;
		nRows = right.nRows;
		nColumns = right.nColumns;
		ptrData = new T[nRows*nColumns]();
	}
	
	for (size_t i = 0; i < getSize(); i++)
	{
		ptrData[i] = (right.ptrData)[i];
	}

	return *this;
}

template <class T>
std::ostream & operator<<(std::ostream & out, const DoubleSubscriptedArray<T>& right);

template <class T>
std::istream & operator>>(std::istream & in, DoubleSubscriptedArray<T>& right);

template <class T>
std::ostream & operator<<(std::ostream & out, const DoubleSubscriptedArray<T>& right)
{
	// TODO: insert return statement here
	int rows, columns;
	right.getShape(rows, columns);
	out << rows << "x" << columns << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			out << std::setw(8) << right(i, j);
		}
		out << std::endl;
	}

	return out;
}

template <class T>
std::istream & operator>>(std::istream & in, DoubleSubscriptedArray<T>& right)
{
	// TODO: insert return statement here
	int rows, columns;
	right.getShape(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			in >> right(i, j);
		}
	}

	return in;
}