#include "Ship.hpp"

Ship::Ship()
{}

Ship::~Ship()
{}

void Ship::damageSys(System value, int damage)
{
    switch (value) {
        case System::Colon: colon_ -= damage; break;
        case System::Atm: atm_ -= damage; break;
        case System::Grav: grav_ -= damage; break;
        case System::Temp: temp_ -= damage; break;
        case System::Water: water_ -= damage; break;
        case System::Res: res_ -= damage; break;
        case System::Landing: landing_ -= damage; break;
        case System::Build: build_ -= damage; break;
        default: throw ShipErr("Not a valid system"); break;
    }
}

short Ship::getColon()const
{
    return colon_;
}

short Ship::getAtm()const
{
    return atm_;
}

short Ship::getGrav()const
{
    return grav_;
}

short Ship::getTemp()const
{
    return temp_;
}

short Ship::getWater()const
{
    return water_;
}

short Ship::getRes()const
{
    return res_;
}

short Ship::getLanding()const
{
    return landing_;
}

short Ship::getBuild()const
{
    return build_;
}
