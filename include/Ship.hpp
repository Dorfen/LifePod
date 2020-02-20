#include <string>

#ifndef _SHIP_HPP_
#define _SHIP_HPP_

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
        short getColon()const;
        short getAtm()const;
        short getGrav()const;
        short getTemp()const;
        short getWater()const;
        short getRes()const;
        short getLanding()const;
        short getBuild()const;

    private:
        short colon_ = 1000;
        short atm_ = 100;
        short grav_ = 100;
        short temp_ = 100;
        short water_ = 100;
        short res_ = 100;
        short landing_ = 100;
        short build_ = 100;
};

class ShipErr: public std::exception
{
    public:
        ShipErr(const std::string &message);
        const std::string getMessage()const;

    private:
        const std::string _message;
};

#endif //_SHIP_HPP_
