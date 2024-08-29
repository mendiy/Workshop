#pragma once
#pragma once
#include "Type.h"
#include <iostream>

class Void : public Type

{
public:
	virtual bool isPrintable() { return false; };
	virtual std::string toString() { return "void"; };
private:
	//std::string _str;
};

