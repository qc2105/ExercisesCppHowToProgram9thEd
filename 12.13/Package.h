#pragma once
#include <string>
#include <iostream>

namespace name12_13 {

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
		Package(Person& Sender, Person& Recipient, double Weight, double CostPerOunce);
		virtual ~Package() {};

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
		virtual double calculateCost(void) const
		{
			return getWeight() * getCostPerOunce();
		}

		virtual void printInfo(void) const
		{
			std::cout << "From: " << sender.name << "\n" << sender.address << ", " << sender.city << ", " << sender.state << ", "
				<< sender.ZIP << "\n\n"
				<< "To: " << recipient.name << "\n" << recipient.address << ", " << recipient.city << ", " << recipient.state << ", "
				<< recipient.ZIP << "\n";
		}

	private:
		Person sender;
		Person recipient;
		double weight;
		double costPerOunce;
	};

}