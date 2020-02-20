#include "Button.hpp"
#include <vector>
#include <iostream>

Button::Button(short system, int dmg, int mult, std::string &msg) :
    system_(system),
    dmg_(dmg),
    mult_(mult),
    msg_(msg)
{
    if (system_ > 8 || system_ < 0)
        throw ButtonErr("Invalid System");
}

Button::Button(std::string str) :
    system_(0),
    dmg_(0),
    mult_(0),
    msg_()
{
    size_t pos = 0;
    const std::string delimiter(":");
    std::vector<std::string> results;

    results.reserve(4);
    while((pos = str.find(delimiter)) != std::string::npos) {
        results.push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
    }
    msg_ = results[0];
    system_ = std::atoi(results[1].c_str());
    if (system_ > 8 || system_ < 0)
        throw ButtonErr("Invalid System");
    dmg_ = std::atoi(results[2].c_str());
    mult_ = std::atoi(str.c_str());
}

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

std::string Button::getMsg()const
{
    return msg_;
}

int Button::rollDmg()const
{
    return (dmg_ * (rand() % mult_ + 1));
}
