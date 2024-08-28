#pragma once
#include "Type.h"
#include "Sequence.h"
#include "Helper.h"
#include <iostream>

class String : public Sequence

{
public:
	String(std::string str)
		: Sequence()
	{

		_str = str;
	}
	~String() {};
	virtual bool isPrintable() { return true; };
	virtual std::string toString();
private:
	std::string _str;

};

