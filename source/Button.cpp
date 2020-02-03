#include "Button.hpp"

Button::Button(short system, int dmg, int mult, std::string &msg) :
    system_(system),
    dmg_(dmg),
    mult_(mult),
    msg_(msg)
{}

Button::~Button()
{}

short Button::getSystem()const
{
    return system_;
}

int Button::getDmg()const
{
    return dmg_;
}

int Button::getMult()const
{
    return mult_;
}

const std::string &Button::getMsg()const
{
    return msg_;
}
