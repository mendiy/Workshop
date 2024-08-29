#include "NameErrorException.h"
#include <memory>
#include <iostream>

const char* NameErrorException::what() const noexcept
{
    std::string msg;

    msg = "NameError: name " +_name + " is not defined";
    char* error = new char[msg.length() + 1];

    for (int i = 0; i < msg.length(); i++)
    {
        error[i] = msg[i];
    }
    error[msg.length()] = 0;

    return error;
}
