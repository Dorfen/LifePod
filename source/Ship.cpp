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
    if (colon_ < 0)
        colon_ = 0;
    if (atm_ < 0)
        atm_ = 0;
    if (grav_ < 0)
        grav_ = 0;
    if (temp_ < 0)
        temp_ = 0;
    if (water_ < 0)
        water_ = 0;
    if (res_ < 0)
        res_ = 0;
    if (landing_ < 0)
        landing_ = 0;
    if (build_ < 0)
        build_ = 0;
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
