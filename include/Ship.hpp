#include <unordered_map>
#include <string>

#ifndef _SHIP_HPP_
#define _SHIP_HPP_

#include "LifepodErr.hpp"

class Ship
{
    public:
        Ship();
        ~Ship();
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
        void damageSys(const System &value, const int damage);
        int getSystemValue(const System &value)const;

    private:
        std::unordered_map<Ship::System, int> _system;
};

class ShipErr: public LifepodErr
{
    public:
        ShipErr(const std::string &message) : LifepodErr(message) {};
};

#endif //_SHIP_HPP_
