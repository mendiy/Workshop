#include "String.h"
#include <iostream>
#include "Helper.h"

std::string String::toString() 
{
    std::string res = _str;
    res = res.substr(1, res.length() - 2);
    
    if (res.find("\'") != std::string::npos)
    {
        return '\"' + res + '\"';
    }
    
    return "\'" + res + "\'";
}
