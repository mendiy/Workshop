#include "Parser.h"
#include "Helper.h"
#include "Integer.h"
#include "String.h"
#include "Void.h"
#include "Boolean.h"
#include <iostream>
#include <unordered_map>
#include "IndentationException.h"
#include "SyntaxException.h"
#include "NameErrorException.h"

std::unordered_map<std::string, Type*> Parser::_variables;


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
		if (makeAssignment(str))
		{
			elm = new Void();
			elm->setIsTemp(true);
			return elm;
		}
		elm = getVariableValue(str);
		if (elm == nullptr)
		{
			if (!isLegalVarName(str))
			{
				throw SyntaxException();
			}
			throw NameErrorException(str);
		}
		
		/*elm = getType(str);
		if (elm == nullptr)
		{
			throw SyntaxException();
		}*/

		if (makeAssignment(str))
		{
			elm = new Void();
			elm->setIsTemp(true);
		}
	}

	return elm;
}

Type* Parser::getType(std::string str)
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

bool Parser::isLegalVarName(std::string str)
{
	Helper::trim(str);
	int i;
	for (i = 1; i < str.length(); i++)
	{
		if (!Helper::isDigit(str[i]) && !Helper::isLetter(str[i]) && !Helper::isUnderscore(str[i]))
		{
			return false;
		}
	}
	return !Helper::isDigit(str[0]);
}

bool Parser::makeAssignment(std::string str)
{

	Type* elm = nullptr;
	std::string varName, value;
	Helper::trim(str);
	
	if (str.find("=") != std::string::npos)
	{
		varName = str.substr(0, str.find("="));
		if (!isLegalVarName(varName))
		{
			throw NameErrorException(varName);
		}
		value = str.substr(str.find("=") + 1, str.length() - 1);
		Helper::trim(value);
		Helper::trim(varName);
		elm = getVariableValue(value);
		if (elm != nullptr)
		{
			//std::cout << "tow vars" << varName << std::endl;
			elm = _variables[value];
			//std::cout << elm->toString() << std::endl;
			Parser::_variables[varName] = elm;
			//std::cout << _variables[varName]->toString() << std::endl;
			return true;
		}
		elm = getType(value);
		if ( elm == nullptr )
		{
			throw SyntaxException();
		}
		Helper::trim(varName);
		Parser::_variables[varName] = elm;
		
		return true;
	}
	return false;
}

Type* Parser::getVariableValue(std::string str)
{
	Helper::trim(str);
	if (_variables.find(str) != _variables.end())
	{
		return _variables[str];
	}
	return nullptr;
}


