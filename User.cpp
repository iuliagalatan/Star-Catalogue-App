#include "User.h"


std::istream& operator >> (std::istream& is, User& item)
{
	std::string line;
	getline(is, line);
	if (line == "")   return is;
	std::vector<std::string> tokens = split(line, ',');


	item.name = trim(tokens[0]);
	item.constelation = trim(tokens[1]);


	//if (tokens.size() != 3) return is;


	/*item.id = trim(tokens[0]);
	item.description = stoi(trim(tokens[1]);
	item.creator = trim(tokens[2]);
	*/

	return is;
}
