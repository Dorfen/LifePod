#include <iostream>
#include "Ship.hpp"
#include "Event.hpp"
#include "Button.hpp"
#include "Screen.hpp"

int main(void)
{
    std::vector<Event> event_list = Event::loadEventDir("./event_data/");
    Ship ship;
    unsigned int event_nbr = 0;

    srand(time(NULL));
    Screen::initScreen();
    Screen s;
    while (ship.getSystemValue(Ship::System::Colon) > 0) {
        try {
            s.displayShipStatus(ship, false);
            s.displayEventTxt(event_list.at(event_nbr).getText(), false);
            s.refreshW();
            if (event_list.at(event_nbr).pressButtons(s, ship))
                event_nbr = rand() % event_list.size();
        } catch (const std::out_of_range &oor) {
            s.cmd_ << "Error: invalid event number.";
            continue;
        } catch (const EventErr &err) {
            if (err.getMessage() == "Quit")
                break;
            else
                throw;
        }
    }
    s.clearW();
    if (ship.getSystemValue(Ship::System::Colon) <= 0)
        mvprintw(LINES/2, COLS/2 - 15, "You lose, all your colons dies");
    else
        mvprintw(LINES/2, COLS/2 - 4, "You win");
    refresh();
    getch();
}
