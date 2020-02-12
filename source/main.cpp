#include <iostream>
#include "Ship.hpp"
#include "Event.hpp"
#include "Button.hpp"
#include "Screen.hpp"

int main(void)
{
    std::vector<Event> event_list = Event::loadEventDir("./event_data/");
    std::string cmd;
    Ship ship;
    int event_nbr = 0;
    Screen s;

    s.printShip(false);
    srand(time(NULL));
    while (ship.getColon() > 0) {
        s.clearW(Screen::Event);
        s.displayShipStatus(ship, false);
        try {
            s.displayEventTxt(event_list.at(event_nbr).getText(), false);
            if (event_list.at(event_nbr).pressButtons(s, ship))
                event_nbr = rand() % event_list.size();
        } catch (const std::out_of_range &oor) {
            s.addToPrompt(std::string("Error: invalid event number.") + oor.what());
            continue;
        } catch (const EventErr &err) {
            if (err.getMessage() == "Quit")
                break;
            else
                throw;
        }
        s.refreshW();
    }
}
