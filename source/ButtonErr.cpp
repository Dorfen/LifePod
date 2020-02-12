#include "Button.hpp"

ButtonErr::ButtonErr(const std::string &message) :
    _message(message)
{}

const std::string &ButtonErr::getMessage()const
{
    return _message;
}
