// Fig. 10.10: Array.h
// Array class definition with overloaded operators.
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <class T>
class Array
{
   friend std::ostream &operator<<( std::ostream &, const Array & );
   friend std::istream &operator>>( std::istream &, Array & );

public:
   explicit Array( int = 10 ); // default constructor
   Array( const Array & ); // copy constructor
   ~Array(); // destructor
   size_t getSize() const; // return size

   const Array &operator=( const Array & ); // assignment operator
   bool operator==( const Array & ) const; // equality operator

   // inequality operator; returns opposite of == operator
   bool operator!=( const Array &right ) const  
   { 
      return ! ( *this == right ); // invokes Array::operator==
   } // end function operator!=
   
   // subscript operator for non-const objects returns modifiable lvalue
   T &operator[]( int );              

   // subscript operator for const objects returns rvalue
   T operator[]( int ) const;  
private:
   size_t size; // pointer-based array size
   T *ptr; // pointer to first element of pointer-based array
}; // end class Array

#endif

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/


 // default constructor for class Array (default size 10)
template <class T>
Array<T>::Array(int arraySize)
    : size(arraySize > 0 ? arraySize :
        throw std::invalid_argument("Array size must be greater than 0")),
    ptr(new T[size])
{
    for (size_t i = 0; i < size; ++i)
        ptr[i] = 0; // set pointer-based array element
} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to an Array
template <class T>
Array<T>::Array(const Array& arrayToCopy)
    : size(arrayToCopy.size),
    ptr(new T[size])
{
    for (size_t i = 0; i < size; ++i)
        ptr[i] = arrayToCopy.ptr[i]; // copy into object
} // end Array copy constructor

// destructor for class Array
template <class T>
Array<T>::~Array()
{
    delete[] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
template <class T>
size_t Array<T>::getSize() const
{
    return size; // number of elements in Array
} // end function getSize

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
template <class T>
const Array<T>& Array<T>::operator=(const Array& right)
{
    if (&right != this) // avoid self-assignment
    {
        // for Arrays of different sizes, deallocate original
        // left-side Array, then allocate new left-side Array
        if (size != right.size)
        {
            delete[] ptr; // release space
            size = right.size; // resize this object
            ptr = new T[size]; // create space for Array copy
        } // end inner if

        for (size_t i = 0; i < size; ++i)
            ptr[i] = right.ptr[i]; // copy array into object
    } // end outer if

    return *this; // enables x = y = z, for example
} // end function operator=

// determine if two Arrays are equal and
// return true, otherwise return false
template <class T>
bool Array<T>::operator==(const Array& right) const
{
    if (size != right.size)
        return false; // arrays of different number of elements

    for (size_t i = 0; i < size; ++i)
        if (ptr[i] != right.ptr[i])
            return false; // Array contents are not equal

    return true; // Arrays are equal
} // end function operator==

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
template <class T>
T& Array<T>::operator[](int subscript)
{
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size)
        throw std::out_of_range("Subscript out of range");

    return ptr[subscript]; // reference return
} // end function operator[]

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
template <class T>
T Array<T>::operator[](int subscript) const
{
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size)
        throw out_of_range("Subscript out of range");

    return ptr[subscript]; // returns copy of this element
} // end function operator[]

// overloaded input operator for class Array;
// inputs values for entire Array
template <class T>
std::istream& operator>>(std::istream& input, Array<T>& a)
{
    for (size_t i = 0; i < a.size; ++i)
        input >> a.ptr[i];

    return input; // enables cin >> x >> y;
} // end function 

// overloaded output operator for class Array
template <class T>
std::ostream& operator<<(std::ostream& output, const Array<T>& a)
{
    // output private ptr-based array 
    for (size_t i = 0; i < a.size; ++i)
    {
        output << setw(12) << a.ptr[i];

        if ((i + 1) % 4 == 0) // 4 numbers per row of output
            output << endl;
    } // end for

    if (a.size % 4 != 0) // end last line of output
        output << endl;

    return output; // enables cout << x << y;
} // end function operator<<

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
