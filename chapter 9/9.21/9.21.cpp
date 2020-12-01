// 9.21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IntegerSet.h"

int main()
{
    std::cout << "Hello World!\n";
	int a1[3] = { 1, 2, 3 };
	int a2[3] = { 2, 3, 4 };

	IntegerSet emptySet;
	emptySet.printSet();

	IntegerSet set1(a1, 3);
	IntegerSet set2(a2, 3);

	set1.unionOfSets(set2).printSet();
	set1.intersectionOfSets(set2).printSet();

	set1.insertElement(4);
	set2.insertElement(1);

	set1.isEqualTo(set2) ? std::cout << "equal" : std::cout << "not equal";
	std::cout << std::endl;

	set1.deleteElement(1);
	set1.printSet();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
