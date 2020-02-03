#include <string>
#include <vector>
#include <memory>
#include "Button.hpp"

#ifndef EVEN_HPP_
#define EVEN_HPP_

class Event
{
    public:
        Event();
        ~Event();
        std::vector<std::string> &getText();
        std::unique_ptr<Button> &getButton(int index);
        std::vector<std::unique_ptr<Button>> &getButtons();

    private:
        std::vector<std::string> txt_;
        std::vector<std::unique_ptr<Button>> button_;
};

#endif //EVEN_HPP_
