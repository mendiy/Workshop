#include "Type.h"
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "[M.M.Y]"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;
	Type* element = nullptr;
	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		try
		{
			// parsing command
			element = Parser::parseString(input_string);
			if (element->isPrintable())
			{
				std::cout << element->toString() << std::endl;
			}
		}
		catch (std::exception& msg)
		{
			std::cout << msg.what() << std::endl;
		}


		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}

	return 0;
}
