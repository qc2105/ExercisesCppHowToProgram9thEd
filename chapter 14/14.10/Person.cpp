#include "Person.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

name14_10::Person::Person(void)
	:id(0),
	age(0),
	firstName(""),
	lastName("unassigned")
{
}

name14_10::Person::Person(const int Id, const std::string & FirstName, const std::string & LastName, int Age)
	:id(Id),
	age(Age)
{
	setFirstName(FirstName);
	setLastName(LastName);
}

void name14_10::Person::setId(int Id)
{
	id = Id;
}

int name14_10::Person::getId() const
{
	return id;
}

void name14_10::Person::setLastName(const std::string & LastName)
{
	size_t length;
	LastName.length() < 15 ? length = LastName.length() : length = 14;
	LastName.copy(lastName, length);
	lastName[length] = '\0';
}

std::string name14_10::Person::getLastName() const
{
	return std::string(lastName);
}

void name14_10::Person::setFirstName(const std::string & FirstName)
{
	size_t length;
	FirstName.length() < 10 ? length = FirstName.length() : length = 9;
	FirstName.copy(firstName, length);
	firstName[length] = '\0';
}

std::string name14_10::Person::getFirstName() const
{
	return std::string(firstName);
}

void name14_10::Person::setAge(int Age)
{
	age = Age;
}

int name14_10::Person::getAge() const
{
	return age;
}

void name14_10::initialize(std::fstream & of)
{
	name14_10::Person person;

	of.seekp(0);

	for (size_t i = 0; i < SIZELIMIT; ++i)
	{
		of.write(reinterpret_cast<const char*>(&person), sizeof(name14_10::Person));
	}

	of.close();
}

bool name14_10::add(std::fstream & f, std::istream &input)
{
	int Id, Age; std::string FirstName, LastName;
	
	std::cout << "Please input the info: Id FirstName LastName Age\n";
	input >> Id >> FirstName >> LastName >> Age;
	f.seekg((Id - 1) * sizeof(name14_10::Person));
	if (!f)
	{
		std::cerr << "Seek faild\n";
		return false;
	}
	
	name14_10::Person temp;
	f.read(reinterpret_cast<char *>(&temp), sizeof(name14_10::Person));
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
		name14_10::Person person(Id, FirstName, LastName, Age);
		f.seekp((Id - 1) * sizeof(name14_10::Person));
		if (!f)
		{
			std::cerr << "Seek for writing faild\n";
			return false;
		}
		f.write(reinterpret_cast<const char*>(&person), sizeof(name14_10::Person));
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

bool name14_10::update(std::fstream & f, std::istream &input)
{
	int Id, Age; std::string FirstName, LastName;

	std::cout << "Please input the info: Id FirstName LastName Age\n";
	input >> Id >> FirstName >> LastName >> Age;
	f.seekg((Id - 1) * sizeof(name14_10::Person));
	if (!f)
	{
		std::cerr << "Seek faild\n";
		return false;
	}

	name14_10::Person temp;
	f.read(reinterpret_cast<char *>(&temp), sizeof(name14_10::Person));
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
		name14_10::Person person(Id, FirstName, LastName, Age);
		f.seekp((Id - 1) * sizeof(name14_10::Person));
		if (!f)
		{
			std::cerr << "Seek for writing faild\n";
			return false;
		}
		f.write(reinterpret_cast<const char*>(&person), sizeof(name14_10::Person));
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

bool name14_10::del(std::fstream & f, std::istream &input)
{
	int Id;
	std::cout << "Please inupt the id of the record to be deleted: \n";
	input >> Id;

	f.seekg((Id - 1) * sizeof(name14_10::Person));
	if (!f)
	{
		std::cerr << "Seek faild\n";
		return false;
	}

	name14_10::Person temp;
	f.read(reinterpret_cast<char *>(&temp), sizeof(name14_10::Person));
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
		name14_10::Person person;
		f.seekp((Id - 1) * sizeof(name14_10::Person));
		if (!f)
		{
			std::cerr << "Seek for writing faild\n";
			return false;
		}
		f.write(reinterpret_cast<const char*>(&person), sizeof(name14_10::Person));
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

void name14_10::print(std::fstream & f, std::ostream &output)
{
	f.seekg(0);
	if (!f)
	{
		std::cerr << "Seek failed\n";
		exit(EXIT_FAILURE);
	}
	output << std::setw(4) << "Id" << std::setw(15) << "First Name" << std::setw(15)
		<< "Last Name" << std::setw(10) << "Age" << std::endl;
	for (size_t i = 0; i < SIZELIMIT; ++i)
	{
		name14_10::Person temp;
		f.read(reinterpret_cast<char *>(&temp), sizeof(name14_10::Person));
		if (!f)
		{
			std::cerr << "Read failed\n";
			exit(EXIT_FAILURE);
		}
		if (temp.getId() != 0)
		{
			output << std::setw(4) << temp.getId() << std::setw(15) << temp.getFirstName()
				<< std::setw(15) << temp.getLastName() 
				<< std::setw(10) << temp.getAge() << std::endl;
		}
	}
}
