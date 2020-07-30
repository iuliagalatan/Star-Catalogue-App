#pragma once
#include <string>
#include <vector>

class Star;
using TElem = Star;

class Star
{
private:
	std::string name;
	std::string constelation;
	std::string RA;
	std::string DEC;
	int diameter;

public:
	TElem() {
		name = "";
		constelation = "";
		RA = "";
		DEC = "";
		diameter = 0;
	}
	TElem(std::string n, std::string conste, std::string ra, std::string dec, int diameter):name{n},
		constelation{ conste }, RA{ra}, DEC{ dec }, diameter{ diameter }{}

	std::string getName() { return name; }
	std::string getConstelation() { return constelation; }
	std::string getRA() { return RA; }
	std::string getDEC() { return DEC; }
	int getDiameter() { return diameter; }

	//void setStatus(std::string newStat) { status = newStat; }

	bool operator < (const TElem& t) const
	{
		return constelation < t.constelation;
	}
	friend std::istream& operator>>(std::istream& istream, TElem& domain);
	friend std::ostream& operator << (std::ostream& ostream, const TElem& element);
};

