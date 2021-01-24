#include <string>
#include <unordered_map>

#ifndef _SHIP_HPP_
#define _SHIP_HPP_

#include "LifepodErr.hpp"

class Ship
{
public:
    enum System {
        Colon = 1,
        Atm = 2,
        Grav = 3,
        Temp = 4,
        Water = 5,
        Res = 6,
        Landing = 7,
        Build = 8,
    };

public:
    Ship();
    ~Ship();
    template <System T>
    int getSystemValue() const
    {
        return _system.at(T);
    }
    void damageSys(const System &value, const int damage);

private:
    std::unordered_map<Ship::System, int> _system;
};

static const std::unordered_map<Ship::System, std::string> System_to_string{
    {Ship::Colon, "Colon"},      {Ship::Atm, "Atmosphere"}, {Ship::Grav, "Gravity"},
    {Ship::Temp, "Temperature"}, {Ship::Water, "Water"},    {Ship::Res, "Resources"},
    {Ship::Landing, "Landing"},  {Ship::Build, "Building"},
};

class ShipErr : public LifepodErr
{
public:
    ShipErr(const std::string &message): LifepodErr(message){};
};

#endif    //_SHIP_HPP_
