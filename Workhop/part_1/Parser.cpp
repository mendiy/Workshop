#include "Parser.h"
#include "Helper.h"
#include "Integer.h"
#include "String.h"
#include "Boolean.h"
#include <iostream>
#include "IndentationException.h"
#include "SyntaxException.h"


Type* Parser::parseString(std::string str)
{
	Type* elm = nullptr;
	if (str.length() > 0)
	{
		Helper::rtrim(str);
		if (str[0] == ' ')
		{
			throw IndentationException();
		}
		elm = getType(str);
		if (elm == nullptr)
		{
			throw SyntaxException();
		}
	}

	return elm;
}

Type* Parser::getType(std::string& str)
{
	Type* temp;
	Helper::trim(str);
	if (Helper::isInteger(str))
	{
		 temp = new Integer(atoi(str.c_str()));
		 temp->setIsTemp(true);
		 return temp;
	}
	if (Helper::isBoolean(str))
	{
		temp = new Boolean(str == "true");
		temp->setIsTemp(true);
		return temp;
	}
	if (Helper::isString(str)) {
		temp = new String(str);
		temp->setIsTemp(true);
		return temp;
	}
	return nullptr;
}


