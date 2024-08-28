#include "Integer.h"
#include "Helper.h"

std::string Integer::toString()
{
	{
		std::string n = std::to_string(_num);
		Helper::removeLeadingZeros(n);
		return n;
	};
    return std::string();
}
