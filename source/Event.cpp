#include "Event.hpp"
#include <fstream>
#include <filesystem>
#include <iostream>

Event::Event() :
    txt_(),
    button_()
{}

Event::Event(const std::string filename) :
    txt_(),
    button_()
{
    size_t nb = 0;
    std::ifstream file;
    std::string line;

    file.open(filename);
    if (!file.is_open())
        throw std::runtime_error("Bad filename");
    std::getline(file, line);
    nb = std::stoi(line);
    button_.reserve(nb);
    for (size_t i = 0; i < nb; i++) {
        std::getline(file, line);
        button_.push_back(Button(line));
    }
    while (std::getline(file, line)) {
        txt_.push_back(line);
    }
    file.close();
}

Event::~Event()
{}

const std::vector<std::string> &Event::getText()const
{
    return txt_;
}

const Button &Event::getButton(int index)const
{
    return button_.at(index);
}

const std::vector<Button> &Event::getButtons()const
{
    return button_;
}

std::vector<Event> Event::loadEventDir(const std::string dir_name)
{
    std::vector<Event> event_list;

    for (const auto &entry : std::filesystem::directory_iterator(dir_name))
        event_list.push_back(Event(entry.path().string()));
    return event_list;
}
