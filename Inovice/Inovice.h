#pragma once
#include <string>

class Inovice
{
public:
	Inovice(std::string& partName, 
		std::string& partDescription,
		int quantity,
		int price);
	~Inovice();
	
	void setPartName(const std::string& partName);
	std::string getPartName() const;
	
	void setPartDescription(const std::string& partDescription);
	std::string getPartDescription() const;

	void setQuantity(const int quantity);
	int getQuantity() const;

	void setPrice(const int price);
	int getPrice() const;

	int getInvoiceAmount() const;
private:
	std::string mPartName;
	std::string mPartDescription;
	int mQuantity;
	int mPrice;
};

