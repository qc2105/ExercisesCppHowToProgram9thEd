// Chapter4-exercises-4.36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

std::vector<unsigned> encrypt(std::vector<unsigned> plainDigits);
std::vector<unsigned> decrypt(std::vector<unsigned> encryptedDigits);

std::vector<unsigned> encrypt(std::vector<unsigned> plainDigits)
{
	for (int i = 0; i < 4; i++)
	{
		plainDigits[i] = (plainDigits[i] + 7) % 10;
	}

	unsigned temp = plainDigits[0];
	plainDigits[0] = plainDigits[2];
	plainDigits[2] = temp;
	temp = plainDigits[1];
	plainDigits[1] = plainDigits[3];
	plainDigits[3] = temp;

	std::cout << "Encrypted: ";

	for (int i = 0; i < 4; i++)
	{
		std::cout << plainDigits[i];
	}
	std::cout << std::endl;

	return plainDigits;
}

std::vector<unsigned> decrypt(std::vector<unsigned> encryptedDigits)
{
	unsigned temp = encryptedDigits[0];
	encryptedDigits[0] = encryptedDigits[2];
	encryptedDigits[2] = temp;
	temp = encryptedDigits[1];
	encryptedDigits[1] = encryptedDigits[3];
	encryptedDigits[3] = temp;

	for (int i = 0; i < 4; i++)
	{
		if (encryptedDigits[i] >= 7)
		{
			encryptedDigits[i] -= 7;
		}
		else
		{
			encryptedDigits[i] = encryptedDigits[i] + 3; // + 10 - 7
		}
	}

	std::cout << "Decrypted: ";
	
	for (int i = 0; i < 4; i++)
	{
		std::cout << encryptedDigits[i];
	}
	std::cout << std::endl;

	return encryptedDigits;
}


int main()
{
    std::cout << "Hello World!\n"; 

	unsigned plain4Digit;
	std::cout << "Input a four digit integer: ";
	std::cin >> plain4Digit;

	while (true)
	{
		if (plain4Digit < 1000 || plain4Digit > 9999)
		{
			std::cout << "Range: [1000, 9999], input again: ";
			std::cin >> plain4Digit;
		}
		else
		{
			break;
		}
	}

	std::vector<unsigned> digits(4);
	digits[0] = plain4Digit / 1000;
	digits[1] = plain4Digit / 100 % 10;
	digits[2] = plain4Digit / 10 % 10;
	digits[3] = plain4Digit % 10;
	
	std::vector<unsigned> encrytpedDigits = encrypt(digits);
	std::vector<unsigned> decryptedDigits = decrypt(encrytpedDigits);

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
