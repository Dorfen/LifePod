#include <string>

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "LifepodErr.hpp"

class Button {
    public:
        Button(short system, int dmg, int mult, std::string &msg);
        Button(std::string str);
        ~Button();
        short getSystem()const;
        int getDmg()const;
        int getMult()const;
        std::string getMsg()const;
        int rollDmg()const;

    private:
        short system_;
        int dmg_;
        int mult_;
        std::string msg_;
};

class ButtonErr: public LifepodErr
{
    public:
        ButtonErr(const std::string &message) : LifepodErr(message) {};
};

#endif //BUTTON_HPP_
