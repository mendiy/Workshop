#include "Parser.h"
#include <iostream>
#include "IndentationException.h"


Type* Parser::parseString(std::string str)
{
	if (str.length() > 0)
	{
		if (str[0] == ' ')
		{
			throw IndentationException();
		}
		std::cout << str << std::endl;
	}

	return nullptr;
}


