#include "PieceWorker.h"
#include <iostream>

PieceWorker::PieceWorker(const std::string & first, const std::string & last, const std::string & ssn, 
	const double WagePerPiece, const unsigned NPieces)
	:Employee(first, last, ssn)
{
	setWagePerPiece(WagePerPiece);
	setNPieces(NPieces);
}

void PieceWorker::setWagePerPiece(const double WagePerPiece)
{
	if (WagePerPiece > 0)
	{
		wagePerPiece = WagePerPiece;
		return;
	}
	throw std::invalid_argument("WagePerPiece must be positive\n");
}

void PieceWorker::setNPieces(const long NPieces)
{
	if (NPieces > 0)
	{
		nPieces = NPieces;
		return;
	}
	throw std::invalid_argument("NPieces must be positive\n");
}

double PieceWorker::earnings(void) const
{
	return getNPieces() * getWagePerPiece();
}

void PieceWorker::print(void) const
{
	std::cout << "PieceWorker object: " << std::endl;
	Employee::print();

	std::cout << "\nWage Per Piece: " << getWagePerPiece() << std::endl;
	std::cout << "Number of Pieces: " << getNPieces() << std::endl;
}
