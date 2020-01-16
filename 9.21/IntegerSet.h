#pragma once
#include <vector>
#include <string>

const int SET_SIZE = 101;

class IntegerSet
{
public:
	explicit IntegerSet(void);
	IntegerSet(int *intArray, int intArraySize);

	IntegerSet unionOfSets(const IntegerSet &b) const;
	IntegerSet intersectionOfSets(const IntegerSet &b) const;
	void insertElement(const int k);
	void deleteElement(const int m);

	void printSet(void) const;
	bool isEqualTo(const IntegerSet &b) const;
	
	std::vector<bool> bitField;

private:
	bool checkInput(int k);
};

