#include "Object.h"
#include "util.h"

std::istream& operator >> (std::istream& is, TElem& item)
{
	std::string line;
	getline(is, line);
	if (line == "")   return is;
	std::vector<std::string> tokens = split(line, ',');


	//if (tokens.size() != 3) return is;


	item.name = trim(tokens[0]);
	item.constelation = trim(tokens[1]);
	item.RA = trim(tokens[2]);
	item.DEC = trim(tokens[3]);
	item.diameter = stoi(trim(tokens[4]));
	


	return is;
}

 std::ostream& operator << (std::ostream& os, const TElem& element)
{
	 os << element.name << "," << element.constelation << "," << element.RA << "," << element.DEC<< ","<< element.diameter;
	return os;
}