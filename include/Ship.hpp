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
        void damageSys(System value, int damage);
        int getColon()const;
        int getAtm()const;
        int getGrav()const;
        int getTemp()const;
        int getWater()const;
        int getRes()const;
        int getLanding()const;
        int getBuild()const;

    private:
        int colon_ = 1000;
        int atm_ = 100;
        int grav_ = 100;
        int temp_ = 100;
        int water_ = 100;
        int res_ = 100;
        int landing_ = 100;
        int build_ = 100;
};

class ShipErr: public LifepodErr
{
    public:
        ShipErr(const std::string &message) : LifepodErr(message) {};
};

#endif //_SHIP_HPP_
