#include "Ship.hpp"

Ship::Ship() :
    _system(8)
{
    _system[System::Colon] = 1000;
    _system[System::Atm] = 100;
    _system[System::Grav] = 100;
    _system[System::Temp] = 100;
    _system[System::Water] = 100;
    _system[System::Res] = 100;
    _system[System::Landing] = 100;
    _system[System::Build] = 100;
}

Ship::~Ship()
{}

void Ship::damageSys(const System &value, const int damage)
{
    _system[value] -= damage;
    if (_system[value] < 0)
        _system[value] = 0;
}

