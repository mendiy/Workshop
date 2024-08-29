#pragma once
#pragma once
#include "InterpreterException.h"
#include <iostream>


class NameErrorException : public InterpreterException
{
	
public:
	NameErrorException(std::string name) :
		InterpreterException() 
	{
		_name = name;
	};
	~NameErrorException() {};
	virtual const char* what() const noexcept;
private:
	std::string _name;
};
