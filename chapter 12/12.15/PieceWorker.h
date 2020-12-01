#pragma once
#include "Employee.h"
class PieceWorker :
	public Employee
{
public:
	PieceWorker(const std::string &first, const std::string &last, const std::string &ssn, 
		const double WagePerPiece, const unsigned NPieces);
	virtual ~PieceWorker() {};
	
	void setWagePerPiece(const double WagePerPiece);
	double getWagePerPiece(void) const
	{
		return wagePerPiece;
	}
	void setNPieces(const long NPieces);
	unsigned getNPieces(void) const
	{
		return nPieces;
	}

	virtual double earnings(void) const override;
	virtual void print(void) const override;

private:
	double wagePerPiece;
	unsigned nPieces;
};

