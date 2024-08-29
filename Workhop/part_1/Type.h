#pragma once
#include <iostream>

class Type
{
	public:
		Type() { _isTemp = false; };
		Type(Type & other);
		~Type() {};
		void setIsTemp(bool state) { _isTemp = state; }
		bool getIsTemp() { return _isTemp; }
		virtual bool isPrintable() = 0;
		virtual std::string toString() = 0;
	private:
		bool _isTemp;

};
