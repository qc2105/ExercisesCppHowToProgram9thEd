#pragma once
#include <string>
#include <iostream>

class Person
{
public:
	
	Person(void);
	Person(const int Id, const std::string & FirstName, const std::string &LastName, int Age);

	void setId(int Id);
	int getId() const;
	
	void setLastName(const std::string & LastName);
	std::string getLastName() const;
	
	void setFirstName(const std::string & FirstName);
	std::string getFirstName() const;

	void setAge(int Age);
	int getAge() const;

private:

	char lastName[15];
	char firstName[10];
	int age;
	int id;
};

const int SIZELIMIT = 100;

//Initialize the of with SIZELIMIT zero Person records;
void initialize(std::fstream &of);

bool add(std::fstream &f, std::istream &input = std::cin);

bool update(std::fstream &f, std::istream &input = std::cin);

bool del(std::fstream &f, std::istream &input = std::cin);

void print(std::fstream &f);
