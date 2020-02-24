// 13.18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

int main()
{
	std::stringstream inputStream("This is a segment%What?");

	char *pChar = new char[inputStream.str().size() + 20];
	memset(pChar, '!', inputStream.str().size() + 20);
	inputStream.getline(pChar, 100, '%');

	std::cout << static_cast<int>(pChar[std::string("This is a segment").size()]) << std::endl;
		
	memset(pChar, '!', inputStream.str().size() + 20);
	inputStream.getline(pChar, 100);
	std::cout << pChar << '\n';

	delete[] pChar;

	std::stringstream inputStream2("This is a segment%What?");
	char *pChar2 = new char[inputStream2.str().size() + 20];
	memset(pChar2, '!', inputStream2.str().size() + 20);
	inputStream2.get(pChar2, 100, '%');

	std::cout << static_cast<int>(pChar2[std::string("This is a segment").size()]) << std::endl;
	
	memset(pChar2, '!', inputStream2.str().size() + 20);
	inputStream2.getline(pChar2, 100);
	std::cout << pChar2 << '\n';


	delete[] pChar2;


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
