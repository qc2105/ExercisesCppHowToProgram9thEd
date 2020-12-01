#pragma once
#include <string>
#include <map>

class PhishingScanner
{
public:
	PhishingScanner(const std::string &signatureFilePath = "PhishingSignatures.txt");

	void reset(void);	// reset occurrences to zero
	double scanning(const std::string& emailFilePath);	// input the path of the email file, output the phishing suspicious scores.

private:
	bool load(void);	// Load data from singnatureFilePath into pointValues and initialize occurences

	std::string signatureFilePath;	// format for each line of the file: signatureString;pointValue. ';' is the delimiter.
	std::map<std::string, double> pointValues;	// point values for each signature
	std::map<std::string, unsigned> occurrences; // signature - occurrence
};

