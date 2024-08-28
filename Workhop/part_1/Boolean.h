#pragma once

#include "Type.h"
#include <iostream>
#include <string>

class Boolean : public Type

{
public:
	Boolean(bool state)
		: Type()
	{
		_state = state;
	}
	~Boolean() {};
	virtual bool isPrintable() { return true; };
	virtual std::string toString() { return std::to_string(_state); };
private:
	bool _state;

};

