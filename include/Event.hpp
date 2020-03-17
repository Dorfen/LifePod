#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <filesystem>
#include <iostream>

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "Ship.hpp"
#include "Screen.hpp"
#include "Button.hpp"
#include "LifepodErr.hpp"

class Event
{
    public:
        Event();
        Event(const std::string filename);
        ~Event();
        const std::vector<std::string> &getText()const;
        const Button &getButton(const int index)const;
        const std::vector<Button> &getButtons()const;
        bool pressButtons(Screen &scr, Ship &ship)const;

    public:
        static std::vector<Event> loadEventDir(const std::string dirName);

    private:
        void printButtons(Screen &scr)const;
        std::vector<std::string> txt_;
        std::vector<Button> button_;
};

class EventErr: public LifepodErr
{
    public:
        EventErr(const std::string &message) : LifepodErr(message) {};
};

#endif //EVENT_HPP_
