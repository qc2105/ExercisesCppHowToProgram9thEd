// 9.14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "HugeInteger.h"

int main()
{
    std::cout << "Hello World!\n";
	std::string num = "-1234";
	std::string num2 = "-222";

	HugeInteger hi;
	hi.input(num);
	hi.output();

	HugeInteger hi2;
	hi2.input(num2);
	hi2.output();

	std::cout << hi2.add(hi).output() << std::endl;
	std::cout << hi2.subtract(hi).output() << std::endl;

	HugeInteger i1("1234");
	HugeInteger i2("1000");

	std::cout << i1.subtract(i2).output() << std::endl;
	std::cout << HugeInteger("1000").subtract(HugeInteger("1234")).output() << std::endl;

	HugeInteger("1234").isEqualTo(HugeInteger("+1234")) ? std::cout << "equal" : std::cout << "!equal";
	std::cout << std::endl;
	
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
