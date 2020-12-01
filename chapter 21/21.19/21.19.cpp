// 21.19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <locale>

// Erase substr from str if it exist in str. Ignore the cases
bool Erase(std::string& str, const std::string& substr);

int main()
{
    std::string byString = "by the way.";
    std::cout << byString;
    std::cout << '\t' << std::boolalpha << Erase(byString, "by") << '\t' << byString << std::endl;
    
    std::string BYstring = "BYE BY THY.";
    std::cout << BYstring;
    std::cout << '\t' << Erase(BYstring, "BY") << '\t' << BYstring << std::endl;
    
    std::string byBYstring = "BYE by the dummy";
    std::cout << byBYstring;
    std::cout << '\t' << Erase(byBYstring, "by") << '\t' << Erase(byBYstring, "BY") << '\t'
    << byBYstring << std::endl;
      
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

bool Erase(std::string& str, const std::string& substr)
{
    if (str.find(substr) == std::string::npos)
    {
        return false;
    }
    
    size_t pos = 0;
    while ((pos = str.find(substr)) != std::string::npos)
    {
        str.erase(pos, substr.size());
    }

    return true;
}
