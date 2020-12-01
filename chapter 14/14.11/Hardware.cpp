#include "Hardware.h"
#include <iomanip>

Hardware::Hardware(void)
	:id(0),
	quantity(0),
	cost(0),
	name("")
{
}

Hardware::Hardware(int Id, const std::string & Name, int Quantity, double Cost)
	:id(Id),
	quantity(Quantity),
	cost(Cost)
{
	setName(Name);
}

void Hardware::setId(int Id)
{
	id = Id;
}

int Hardware::getId(void) const
{
	return id;
}

void Hardware::setName(const std::string & Name)
{
	size_t length;
	Name.length() < 20 ? length = Name.length() : length = NAMESIZE - 1;
	Name.copy(this->name, length);
	this->name[NAMESIZE - 1] = '\0';
}

std::string Hardware::getName(void) const
{
	return std::string(name);
}

void Hardware::setQuantity(int Quantity)
{
	quantity = Quantity;
}

int Hardware::getQuantity(void) const
{
	return quantity;
}

void Hardware::setCost(double Cost)
{
	cost = Cost;
}

double Hardware::getCost(void) const
{
	return cost;
}

bool initialize(std::fstream &output)
{
	output.seekp(0);
	if (!output)
	{
		std::cerr << "Seek error\n";
		return false;
	}
	Hardware hdware;

	for (size_t i = 0; i < RECORDSLIMIT; ++i)
	{
		output.write(reinterpret_cast<const char*>(&hdware), sizeof(Hardware));
		if (!output)
		{
			std::cerr << "Write error\n";
			return false;
		}
	}

	return true;
}

bool add(std::fstream &iof, std::istream &input)
{
	int id = getInputId(input);
	iof.seekg((id - 1) * sizeof(Hardware));
	if (!iof)
	{
		std::cerr << "Seek error\n";
		return false;
	}
	Hardware temp;
	iof.read(reinterpret_cast<char *>(&temp), sizeof(Hardware));
	if (!iof)
	{
		std::cerr << "Read error\n";
		return false;
	}
	if (temp.getId() != 0)
	{
		std::cerr << "Error: the id exists\n";
		return false;
	}

	Hardware hdware;
	hdware.setId(id);
	std::cout << "Input the hardware name (end with ';'):\n";
	char name[20];
	std::cin.ignore();
	std::cin.getline(name, 19, ';');
	name[19] = '\0';
	hdware.setName(std::string(name));
	std::cout << "Input quantity cost:\n";
	int quantity; double cost;
	std::cin >> quantity >> cost;
	hdware.setCost(cost);
	hdware.setQuantity(quantity);

	iof.seekp((id - 1) * sizeof(hdware));
	if (!iof)
	{
		std::cerr << "Seek error\n";
		return false;
	}
	iof.write(reinterpret_cast<const char *>(&hdware), sizeof(Hardware));
	if (!iof)
	{
		std::cerr << "Write error\n";
		return false;
	}
	std::cout << "Added: ";
	outputRecord(hdware, std::cout);
	return true;
}

bool del(std::fstream &iof, std::istream &input)
{
	int id = getInputId(input);
	iof.seekg((id - 1) * sizeof(Hardware));
	if (!iof)
	{
		std::cerr << "Seek error\n";
		return false;
	}
	Hardware temp;
	iof.read(reinterpret_cast<char *>(&temp), sizeof(Hardware));
	if (!iof)
	{
		std::cerr << "Read error\n";
		return false;
	}
	if (temp.getId() == 0)
	{
		std::cerr << "The id doesn't exist\n";
		return false;
	}

	iof.seekp((id - 1) * sizeof(Hardware));
	if (!iof)
	{
		std::cerr << "Seek error\n";
		return false;
	}
	Hardware hdware;
	iof.write(reinterpret_cast<const char*>(&hdware), sizeof(Hardware));
	if (!iof)
	{
		std::cerr << "Write error\n";
		return false;
	}
	std::cout << "Deleted: ";
	outputRecord(temp, std::cout);
	return true;
}

bool update(std::fstream &iof, std::istream &input)
{
	int id = getInputId(input);
	iof.seekg((id - 1) * sizeof(Hardware));
	if (!iof)
	{
		std::cerr << "Seek error\n";
		return false;
	}
	Hardware temp;
	iof.read(reinterpret_cast<char *>(&temp), sizeof(Hardware));
	if (!iof)
	{
		std::cerr << "Read error\n";
		return false;
	}
	if (temp.getId() == 0)
	{
		std::cerr << "The id doesn't exist\n";
		return false;
	}
	
	Hardware hdware;
	hdware.setId(id);
	std::cout << "Input the hardware name (end with ';'):\n";
	char name[20];
	std::cin.ignore();
	std::cin.getline(name, 19, ';');
	name[19] = '\0';
	hdware.setName(std::string(name));
	std::cout << "Input quantity cost:\n";
	int quantity; double cost;
	std::cin >> quantity >> cost;
	hdware.setCost(cost);
	hdware.setQuantity(quantity);

	iof.seekp((id - 1) * sizeof(hdware));
	if (!iof)
	{
		std::cerr << "Seek error\n";
		return false;
	}
	iof.write(reinterpret_cast<const char *>(&hdware), sizeof(Hardware));
	if (!iof)
	{
		std::cerr << "Write error\n";
		return false;
	}
	std::cout << "Old: ";
	outputRecord(temp, std::cout);
	std::cout << "Updated: ";
	outputRecord(hdware, std::cout);
	return true;
}

void print(std::fstream &inf, std::ostream &output)
{
	inf.seekg(0);
	if (!inf)
	{
		std::cerr << "Seek error\n";
		return;
	}
	output << std::setw(3) << "Id" << std::setw(20) << "Name" << std::setw(15) << "Quantity"
		<< std::setw(10) << "Cost" << std::endl;

	while (inf)
	{
		Hardware hdware;
		inf.read(reinterpret_cast<char *>(&hdware), sizeof(Hardware));
		if (inf && hdware.getId() != 0)
		{
			outputRecord(hdware, std::cout);
		}
	}
}

void outputRecord(Hardware &hdware, std::ostream &output)
{
	output << std::setw(3) << hdware.getId() << std::setw(20) << hdware.getName() << std::setw(15) << hdware.getQuantity()
		<< std::setw(10) << hdware.getCost() << std::endl;
}

int getInputId(std::istream &input, std::string prompt)
{
	int id = 0;
	std::cout << prompt;
	input >> id;

	while (id <= 0 || id > 100)
	{
		std::cout << "Invalid\n"
			<< "Valid range [1, 100]\n" << std::endl;
		input >> id;
	}

	return id;
}