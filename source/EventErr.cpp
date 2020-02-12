#include "Event.hpp"

EventErr::EventErr(const std::string &message) :
    _message(message)
{}

const std::string &EventErr::getMessage()const
{
    return _message;
}
