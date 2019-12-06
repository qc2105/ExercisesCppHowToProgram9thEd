// 8.17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Simpletron.h"


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <path to sml source file>\n";
		exit(-1);
	}
		
	Simpletron theSimpletron;

	theSimpletron.loadSource(argv[1]);
	theSimpletron.execute();

	return 0;
}

