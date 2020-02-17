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

class Event
{
    public:
        Event();
        Event(const std::string filename);
        ~Event();
        const std::vector<std::string> &getText()const;
        const Button &getButton(int index)const;
        const std::vector<Button> &getButtons()const;
        bool pressButtons(Screen &scr, Ship &ship)const;

    public:
        static std::vector<Event> loadEventDir(const std::string dirName);

    private:
        std::string printButtons(Screen &scr)const;
        std::vector<std::string> txt_;
        std::vector<Button> button_;
};

class EventErr
{
    public:
        EventErr(const std::string &message);
        const std::string &getMessage()const;

    private:
        const std::string _message;
};

#endif //EVENT_HPP_
