#include "Person.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

Person::Person(void)
	:id(0),
	age(0),
	firstName(""),
	lastName("unassigned")
{
}

Person::Person(const int Id, const std::string & FirstName, const std::string & LastName, int Age)
	:id(Id),
	age(Age)
{
	setFirstName(FirstName);
	setLastName(LastName);
}

void Person::setId(int Id)
{
	id = Id;
}

int Person::getId() const
{
	return id;
}

void Person::setLastName(const std::string & LastName)
{
	size_t length;
	LastName.length() < 15 ? length = LastName.length() : length = 14;
	LastName.copy(lastName, length);
	lastName[length] = '\0';
}

std::string Person::getLastName() const
{
	return std::string(lastName);
}

void Person::setFirstName(const std::string & FirstName)
{
	size_t length;
	FirstName.length() < 10 ? length = FirstName.length() : length = 9;
	FirstName.copy(firstName, length);
	firstName[length] = '\0';
}

std::string Person::getFirstName() const
{
	return std::string(firstName);
}

void Person::setAge(int Age)
{
	age = Age;
}

int Person::getAge() const
{
	return age;
}

void initialize(std::fstream & of)
{
	Person person;

	of.seekp(0);

	for (size_t i = 0; i < SIZELIMIT; ++i)
	{
		of.write(reinterpret_cast<const char*>(&person), sizeof(Person));
	}

	of.close();
}

bool add(std::fstream & f, std::istream &input)
{
	int Id, Age; std::string FirstName, LastName;
	
	std::cout << "Please input the info: Id First Name Last Name Age\n";
	input >> Id >> FirstName >> LastName >> Age;
	f.seekg((Id - 1) * sizeof(Person));
	if (!f)
	{
		std::cerr << "Seek faild\n";
		return false;
	}
	
	Person temp;
	f.read(reinterpret_cast<char *>(&temp), sizeof(Person));
	if (!f)
	{
		std::cerr << "Read failed\n";
		return false;
	}

	if (temp.getId() != 0)
	{
		std::cout << "The Id exists please enter another one\n";
		return false;
	}
	if (Id < 100 && Id > 0)
	{
		Person person(Id, FirstName, LastName, Age);
		f.seekp((Id - 1) * sizeof(Person));
		if (!f)
		{
			std::cerr << "Seek for writing faild\n";
			return false;
		}
		f.write(reinterpret_cast<const char*>(&person), sizeof(Person));
		if (!f)
		{
			std::cerr << "writing faild\n";
			return false;
		}
		std::cout << "Added: " << person.getId() << ", " << person.getFirstName() << ", "
			<< person.getLastName() << ", " << person.getAge() << std::endl;
		return true;
	}
	else
	{
		std::cout << "Invalid Id. Valid Id range: (0,100)\n";
	}
	
	return false;	
}

bool update(std::fstream & f, std::istream &input)
{
	int Id, Age; std::string FirstName, LastName;

	std::cout << "Please input the info: Id First Name Last Name Age\n";
	input >> Id >> FirstName >> LastName >> Age;
	f.seekg((Id - 1) * sizeof(Person));
	if (!f)
	{
		std::cerr << "Seek faild\n";
		return false;
	}

	Person temp;
	f.read(reinterpret_cast<char *>(&temp), sizeof(Person));
	if (!f)
	{
		std::cerr << "Read failed\n";
		return false;
	}

	if (temp.getId() == 0)
	{
		std::cerr << "The Id doesn't exist\n";
		return false;
	}
	else
	{
		std::cout << "Old: " << temp.getId() << ", " << temp.getFirstName() << ", "
			<< temp.getLastName() << ", " << temp.getAge() << std::endl;
	}
	if (Id < SIZELIMIT && Id > 0)
	{
		Person person(Id, FirstName, LastName, Age);
		f.seekp((Id - 1) * sizeof(Person));
		if (!f)
		{
			std::cerr << "Seek for writing faild\n";
			return false;
		}
		f.write(reinterpret_cast<const char*>(&person), sizeof(Person));
		if (!f)
		{
			std::cerr << "writing faild\n";
			return false;
		}
		std::cout << "Updated: " << person.getId() << ", " << person.getFirstName() << ", "
			<< person.getLastName() << ", " << person.getAge() << std::endl;
		return true;
	}
	else
	{
		std::cout << "Invalid Id. Valid Id range: (0,100)\n";
	}

	return false;
}

bool del(std::fstream & f, std::istream &input)
{
	int Id;
	std::cout << "Please inupt the id of the record to be deleted: \n";
	input >> Id;

	f.seekg((Id - 1) * sizeof(Person));
	if (!f)
	{
		std::cerr << "Seek faild\n";
		return false;
	}

	Person temp;
	f.read(reinterpret_cast<char *>(&temp), sizeof(Person));
	if (!f)
	{
		std::cerr << "Read failed\n";
		return false;
	}

	if (temp.getId() == 0)
	{
		std::cerr << "The Id doesn't exist\n";
		return false;
	}
	else
	{
		std::cout << "Old: " << temp.getId() << ", " << temp.getFirstName() << ", "
			<< temp.getLastName() << ", " << temp.getAge() << std::endl;
	}

	if (Id < SIZELIMIT && Id > 0)
	{
		Person person;
		f.seekp((Id - 1) * sizeof(Person));
		if (!f)
		{
			std::cerr << "Seek for writing faild\n";
			return false;
		}
		f.write(reinterpret_cast<const char*>(&person), sizeof(Person));
		if (!f)
		{
			std::cerr << "writing faild\n";
			return false;
		}
		std::cout << "Deleted\n";
		return true;
	}
	else
	{
		std::cout << "Invalid Id. Valid Id range: (0,100)\n";
	}

	return false;
}

void print(std::fstream & f)
{
	f.seekg(0);
	if (!f)
	{
		std::cerr << "Seek failed\n";
		exit(EXIT_FAILURE);
	}
	std::cout << std::setw(4) << "Id" << std::setw(15) << "First Name" << std::setw(15)
		<< "Last Name" << std::setw(10) << "Age" << std::endl;
	for (size_t i = 0; i < SIZELIMIT; ++i)
	{
		Person temp;
		f.read(reinterpret_cast<char *>(&temp), sizeof(Person));
		if (!f)
		{
			std::cerr << "Read failed\n";
			exit(EXIT_FAILURE);
		}
		if (temp.getId() != 0)
		{
			std::cout << std::setw(4) << temp.getId() << std::setw(15) << temp.getFirstName() 
				<< std::setw(15) << temp.getLastName() 
				<< std::setw(10) << temp.getAge() << std::endl;
		}
	}
}
