#include "pch.h"
#include "../12.12/SalariedEmployee.h"

class TestEmployee : public ::testing::Test
{
protected:
	TestEmployee()
		:firstName("Chuan"),
		lastName("Qin"),
		socialSecurityNumber("111-1111-1111"),
		birthDate(1,1,1900),
		salary(8000),
		semp(firstName, lastName, socialSecurityNumber, salary)
	{

	};

	virtual ~TestEmployee()
	{};

	std::string firstName;
	std::string lastName;
	std::string socialSecurityNumber;
	Date birthDate;
	double salary;
	SalariedEmployee semp;
};

TEST_F(TestEmployee, TestDefaultBirthdate)
{
	Date BirthDate = Date(1, 1, 1900);
	Date realDate = semp.getBirthDate();

	EXPECT_EQ(BirthDate, realDate);
}

TEST_F(TestEmployee, TestSetBirthDate)
{
	Date expectDate(1, 1, 1990);
	semp.setBirthDate(1, 1, 1990);

	EXPECT_EQ(expectDate, semp.getBirthDate());
}