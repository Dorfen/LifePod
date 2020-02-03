#include <string>
#ifndef _SHIP_HPP_
#define _SHIP_HPP_

class Ship
{
    public:
        Ship();
        ~Ship();
        enum System {
            Colon,
            Atm,
            Grav,
            Temp,
            Water,
            Res,
            Landing,
            Build,
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
        std::string _message;
};

#endif //_SHIP_HPP_
