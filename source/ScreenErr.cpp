#include "Screen.hpp"

ScreenErr::ScreenErr(const std::string &message) :
    _message(message)
{}

const std::string ScreenErr::getMessage()const
{
    return _message;
}
