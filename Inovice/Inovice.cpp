// Inovice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Inovice.h"

class heartPurifier
{
public:
	heartPurifier(std::string& purifierName) { mName = purifierName; };
	std::string name() const { return mName; }
private:
	std::string mName;
};

int main()
{
	std::string type1 = "Type 1";
	heartPurifier purifier(type1);

	std::cout << purifier.name() << std::endl;

	std::string type = "type1";
	std::string desc = "type1s";

	Inovice* pIno = new Inovice(type, desc, 3000, 666);

	std::cout << pIno->getPartName() << ", " << pIno->getPartDescription() << "\tTotal: " << pIno->getInvoiceAmount() << std::endl;

	delete pIno;

    std::cout << "Hello World!\n"; 
	
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

Inovice::Inovice(std::string& partName,
	std::string& partDescription,
	int quantity,
	int price):
	mPartName(partName),
	mPartDescription(partDescription),
	mQuantity(quantity),
	mPrice(price)
{
	//validation
	setQuantity(quantity);
	setPrice(price);
}

Inovice::~Inovice()
{
}

void Inovice::setPartName(const std::string & partName)
{
	mPartName = partName;
}

std::string Inovice::getPartName() const
{
	return mPartName;
}

void Inovice::setPartDescription(const std::string & partDescription)
{
	mPartDescription = partDescription;
}

std::string Inovice::
getPartDescription() const
{
	return mPartDescription;
}

void Inovice::setQuantity(const int quantity)
{
	if (quantity <= 0)
	{
		mQuantity = 0;
	}
	else
	{
		mQuantity = quantity;
	}
}

int Inovice::getQuantity() const
{
	return mQuantity;
}

void Inovice::setPrice(const int price)
{
	if (price <= 0)
	{
		mPrice = 0;
	}
	else
	{
		mPrice = price;
	}
}

int Inovice::getPrice() const
{
	return mPrice;
}

int Inovice::getInvoiceAmount() const
{
	if (getPrice() <= 0 || getQuantity() <= 0)
	{
		return 0;
	}
	return getPrice() * getQuantity();
}
