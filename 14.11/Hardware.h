#pragma once
#include <string>
#include <iostream>
#include <fstream>

const int NAMESIZE = 20;
const int RECORDSLIMIT = 100;

class Hardware
{
public:
	Hardware(void);
	Hardware(int Id, const std::string &Name, int Quantity, double Cost);

	void setId(int Id);
	int getId(void) const;

	void setName(const std::string &Name);
	std::string getName(void) const;

	void setQuantity(int Quantity);
	int getQuantity(void) const;

	void setCost(double Cost);
	double getCost(void) const;

private:
	int id;
	char name[NAMESIZE];
	int quantity;
	double cost;
};

bool initialize(std::fstream &output);

bool add(std::fstream &iof, std::istream &input = std::cin);

bool del(std::fstream &iof, std::istream &input = std::cin);

bool update(std::fstream &iof, std::istream &input = std::cin);

void print(std::fstream &inf, std::ostream &output = std::cout);

void outputRecord(Hardware &hdware, std::ostream &output = std::cout);

int getInputId(std::istream &input, std::string prompt = "Please input id:\n");