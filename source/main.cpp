#include <iostream>
#include "Ship.hpp"
#include "Event.hpp"
#include "Button.hpp"
#include "Screen.hpp"

int main(void)
{
    std::vector<Event> event_list = Event::loadEventDir("./event_data/");
    Ship ship;
    int event_nbr = 0;
    Screen s;

    s.printShip(false);
    srand(time(NULL));
    while (ship.getColon() > 0) {
        s.clearW(Screen::Event);
        event_nbr = rand() % event_list.size();
        s.displayShipStatus(ship, false);
        try {
            s.displayEventTxt(event_list.at(event_nbr).getText(), false);
        } catch(const std::out_of_range &oor) {
            std::cerr << "Error: invalid event number." << oor.what() << std::endl;
            continue;
        }
        s.refreshW();
        if (getch() == 'q')
            break;
    }
}
