#include "pch.h"
#include "../14.10/Person.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class PersonTest : public ::testing::Test
{
protected:
	PersonTest()
		:ioPerson("persons.dat", std::ios::out | std::ios::binary),
		InvalidPerson1(-1, "Someguy", "forker", 11),
		InvalidPerson0(0, "Dummy", "Foo", 1),
		person1(1, "First", "Q", 9999),
		person22(22, "John", "Wick", 33),
		person99(99, "Peter", "Wong", 99),
		InvalidPerson100(100, "Jeff", "American", 100)
	{
	}
	virtual ~PersonTest()
	{

	}

	virtual void SetUp() override
	{
		initialize(ioPerson);
		ioPerson.close();
		ioPerson.open("persons.dat", std::ios::in | std::ios::out | std::ios::binary);
		if (!ioPerson)
		{
			std::cerr << "Open file failed\n";
			FAIL();
		}
	}

	virtual void TearDown() override
	{
		ioPerson.close();
	}

	std::fstream ioPerson;
	Person InvalidPerson1;
	Person InvalidPerson0;
	Person person1;
	Person person22;
	Person person99;
	Person InvalidPerson100;
};

TEST_F(PersonTest, TestInitialize)
{
	ioPerson.seekg(0);
	if (!ioPerson)
	{
		std::cerr << "Seek error\n";
		FAIL();
	}

	for (size_t i = 0; i < SIZELIMIT; ++i)
	{
		Person temp(person99);
		ioPerson.read(reinterpret_cast<char *>(&temp), sizeof(Person));
		if (!ioPerson)
		{
			std::cerr << "Read error\n";
			FAIL();
		}

		ASSERT_EQ(temp.getId(), 0);
		ASSERT_EQ(temp.getFirstName(), "");
		ASSERT_EQ(temp.getLastName(), "unassigned");
		ASSERT_EQ(temp.getAge(), 0);
	}
}

TEST_F(PersonTest, TestAddInvalidInput0)
{
	std::stringstream invalidInput0(std::to_string(InvalidPerson0.getId()) + ' ' + InvalidPerson0.getFirstName() + ' ' +
		InvalidPerson0.getLastName() + ' ' + std::to_string(InvalidPerson0.getAge()));
	ASSERT_FALSE(add(ioPerson, invalidInput0));
}

TEST_F(PersonTest, TestAddInvalidInput1)
{
	std::stringstream invalidInput1(std::to_string(InvalidPerson1.getId()) + ' ' + InvalidPerson1.getFirstName() + ' ' +
		InvalidPerson1.getLastName() + ' ' + std::to_string(InvalidPerson1.getAge()));
	ASSERT_FALSE(add(ioPerson, invalidInput1));
}

TEST_F(PersonTest, TestAddInvalidInput2)
{
	std::stringstream invalidInput100(std::to_string(InvalidPerson100.getId()) + ' ' + InvalidPerson100.getFirstName() + ' ' +
		InvalidPerson100.getLastName() + ' ' + std::to_string(InvalidPerson100.getAge()));
	ASSERT_FALSE(add(ioPerson, invalidInput100));
}

TEST_F(PersonTest, TestAddValid0)
{
	std::stringstream validInput0(std::to_string(person1.getId()) + ' ' + person1.getFirstName() + ' ' +
		person1.getLastName() + ' ' + std::to_string(person1.getAge()));
	ASSERT_TRUE(add(ioPerson, validInput0));

	ioPerson.flush();

	ioPerson.seekg((person1.getId() - 1) * sizeof(Person));
	if (!ioPerson)
	{
		std::cerr << "Seek error\n";
		FAIL();
	}
	Person temp;
	ioPerson.read(reinterpret_cast<char *>(&temp), sizeof(Person));
	if (!ioPerson)
	{
		std::cerr << "Read error\n";
		FAIL();
	}

	ASSERT_EQ(temp.getId(), 1);
	ASSERT_EQ(temp.getFirstName(), "First");
	ASSERT_EQ(temp.getLastName(), "Q");
	ASSERT_EQ(temp.getAge(), 9999);
}

TEST_F(PersonTest, TestAddValid1)
{
	std::stringstream validInput0(std::to_string(person22.getId()) + ' ' + person22.getFirstName() + ' ' +
		person22.getLastName() + ' ' + std::to_string(person22.getAge()));
	ASSERT_TRUE(add(ioPerson, validInput0));

	ioPerson.flush();

	ioPerson.seekg((person22.getId() - 1) * sizeof(Person));
	if (!ioPerson)
	{
		std::cerr << "Seek error\n";
		FAIL();
	}
	Person temp;
	ioPerson.read(reinterpret_cast<char *>(&temp), sizeof(Person));
	if (!ioPerson)
	{
		std::cerr << "Read error\n";
		FAIL();
	}

	ASSERT_EQ(temp.getId(), 22);
	ASSERT_EQ(temp.getFirstName(), "John");
	ASSERT_EQ(temp.getLastName(), "Wick");
	ASSERT_EQ(temp.getAge(), 33);
}

TEST_F(PersonTest, TestAddValid2)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	ASSERT_TRUE(add(ioPerson, validInput0));

	ioPerson.flush();

	ioPerson.seekg((person99.getId() - 1) * sizeof(Person));
	if (!ioPerson)
	{
		std::cerr << "Seek error\n";
		FAIL();
	}
	Person temp;
	ioPerson.read(reinterpret_cast<char *>(&temp), sizeof(Person));
	if (!ioPerson)
	{
		std::cerr << "Read error\n";
		FAIL();
	}

	ASSERT_EQ(temp.getId(), 99);
	ASSERT_EQ(temp.getFirstName(), "Peter");
	ASSERT_EQ(temp.getLastName(), "Wong");
	ASSERT_EQ(temp.getAge(), 99);
}

TEST_F(PersonTest, TestUpdateValid1)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	if (!add(ioPerson, validInput0))
	{
		std::cerr << "Error adding\n";
		FAIL();
	}

	std::stringstream validInput1(std::to_string(person99.getId()) + ' ' + person22.getFirstName() + ' ' +
		person22.getLastName() + ' ' + std::to_string(person22.getAge()));
	ASSERT_TRUE(update(ioPerson, validInput1));

	ioPerson.seekg((person99.getId() - 1) * sizeof(Person));
	if (!ioPerson)
	{
		std::cerr << "Seek error\n";
		FAIL();
	}
	Person temp;
	ioPerson.read(reinterpret_cast<char *>(&temp), sizeof(Person));
	ASSERT_EQ(temp.getId(), 99);
	ASSERT_EQ(temp.getFirstName(), person22.getFirstName());
	ASSERT_EQ(temp.getLastName(), person22.getLastName());
	ASSERT_EQ(temp.getAge(), person22.getAge());
}

TEST_F(PersonTest, TestUpdateInvalid1)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	if (!add(ioPerson, validInput0))
	{
		std::cerr << "Error adding\n";
		FAIL();
	}

	std::stringstream validInput1(std::to_string(person22.getId()) + ' ' + person22.getFirstName() + ' ' +
		person22.getLastName() + ' ' + std::to_string(person22.getAge()));
	ASSERT_FALSE(update(ioPerson, validInput1));
}

TEST_F(PersonTest, TestDelValid1)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	if (!add(ioPerson, validInput0))
	{
		std::cerr << "Error adding\n";
		FAIL();
	}

	std::stringstream validInput1(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	ASSERT_TRUE(del(ioPerson, validInput1));
}

TEST_F(PersonTest, TestDelInvalid1)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	if (!add(ioPerson, validInput0))
	{
		std::cerr << "Error adding\n";
		FAIL();
	}

	std::stringstream validInput1(std::to_string(person22.getId()) + ' ' + person22.getFirstName() + ' ' +
		person22.getLastName() + ' ' + std::to_string(person22.getAge()));
	ASSERT_FALSE(del(ioPerson, validInput1));
}

TEST_F(PersonTest, TestDelInvalid2)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	if (!add(ioPerson, validInput0))
	{
		std::cerr << "Error adding\n";
		FAIL();
	}

	std::stringstream invalidInput100(std::to_string(InvalidPerson100.getId()) + ' ' + InvalidPerson100.getFirstName() + ' ' +
		InvalidPerson100.getLastName() + ' ' + std::to_string(InvalidPerson100.getAge()));
	ASSERT_FALSE(del(ioPerson, invalidInput100));
}

