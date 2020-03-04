#include "LifepodErr.hpp"

LifepodErr::LifepodErr(const std::string &message) :
    _message(message)
{}

const std::string LifepodErr::getMessage()const
{
    return _message;
}
