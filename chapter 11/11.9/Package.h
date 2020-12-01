#pragma once
#include <string>
#include <stdexcept>

class Person
{
public:
	Person(std::string Name, std::string Address, std::string City,
		std::string State, std::string Zip)
		:name(Name),
		address(Address),
		city(City),
		state(State),
		ZIP(Zip)
	{

	}
	Person() {};
	std::string name;
	std::string address;
	std::string city;
	std::string state;
	std::string ZIP;
};

class Package
{
public:
	Package(Person &Sender, Person &Recipient, double Weight, double CostPerOunce);
	
	void setWeight(const double weightInput);
	double getWeight(void) const
	{
		return weight;
	}
	void setCostPerOunce(const double valueInput);
	double getCostPerOunce(void) const
	{
		return costPerOunce;
	}
	double calculateCost(void) const
	{
		return getWeight() * getCostPerOunce();
	}

private:
	Person sender;
	Person recipient;
	double weight;
	double costPerOunce;
};

