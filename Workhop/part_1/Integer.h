#pragma once
#include "Type.h"
#include "Helper.h"
#include <iostream>
#include <string>

class Integer : public Type

{
public:
	Integer(int num) 
		: Type()
	{
		_num = num;
	}
	~Integer() {};
	virtual bool isPrintable() { return true; };
	virtual std::string toString();
private:
	int _num;

};

