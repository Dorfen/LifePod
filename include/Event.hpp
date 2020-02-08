#include <string>
#include <vector>
#include <memory>
#include "Button.hpp"

#ifndef EVENT_HPP_
#define EVENT_HPP_

class Event
{
    public:
        Event();
        Event(const std::string filename);
        ~Event();
        const std::vector<std::string> &getText()const;
        const Button &getButton(int index)const;
        const std::vector<Button> &getButtons()const;
        static std::vector<Event> loadEventDir(const std::string dirName);

    private:
        std::vector<std::string> txt_;
        std::vector<Button> button_;
};

#endif //EVENT_HPP_
