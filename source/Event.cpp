#include "Event.hpp"

Event::Event() :
    txt_(),
    button_()
{}

Event::~Event()
{}

std::vector<std::string> &Event::getText()
{
    return txt_;
}

std::unique_ptr<Button> &Event::getButton(int index)
{
    return button_.at(index);
}

std::vector<std::unique_ptr<Button>> &Event::getButtons()
{
    return button_;
}
