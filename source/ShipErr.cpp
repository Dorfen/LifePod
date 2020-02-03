#include "Ship.hpp"

ShipErr::ShipErr(const std::string &message) :
    _message(message)
{}

const std::string ShipErr::getMessage()const
{
    return _message;
}
