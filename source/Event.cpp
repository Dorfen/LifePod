#include "Event.hpp"

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

bool Event::pressButtons(Screen &scr, Ship &ship)const
{
    char c = '\0';
    std::string str;
    int dmg = 0;

    scr.cmd_ << "--------------------" << printButtons(scr) << "";
    //scr.cmd_.addToPrompt("--------------------");
    //scr.cmd_.addToPrompt(printButtons(scr));
    //scr.cmd_.addToPrompt("", true);
    c = getch();
    if (c == 'q')
        throw EventErr("Quit");
    try {
        if (c < '0' || c > '9')
            throw std::invalid_argument("Not a number");
        dmg = button_.at(c - 48 - 1).rollDmg();
        ship.damageSys(Ship::System(button_.at(c - 48 - 1).getSystem()), dmg);
        str += c;
        str += " take ";
        str += std::to_string(dmg);
        str += " damges";
        scr.cmd_ << str;
    } catch (const std::out_of_range &oor) {
        scr.cmd_ << "Not a valid choice.";
        return false;
    } catch (const ShipErr &ser) {
        scr.cmd_ << ser.getMessage();
        return false;
    } catch (const std::invalid_argument &ia) {
        scr.cmd_ << "Not a valid Command";
        return false;
    }
    scr.cmd_ << "";
    return true;
}

std::string Event::printButtons(Screen &scr)const
{
    std::string str(" ");
    int coord[2] = {-1, -1};

    getmaxyx(scr.cmd_.getWindow(), coord[0], coord[1]);
    for (long unsigned int i = 0; i < button_.size(); i++) {
        str += button_.at(i).getMsg();
        str += "    ";
    }
    return str;
}

std::vector<Event> Event::loadEventDir(const std::string dir_name)
{
    std::vector<Event> event_list;

    for (const auto &entry : std::filesystem::directory_iterator(dir_name))
        event_list.push_back(Event(entry.path().string()));
    return event_list;
}
