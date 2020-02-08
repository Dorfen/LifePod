#include "Ship.hpp"
#include "Event.hpp"
#include "Button.hpp"
#include "Screen.hpp"

int main(void)
{
    std::vector<Event> event_list = Event::loadEventDir("./event_data/");
    Screen s;
    Ship ship;

    s.printShip(false);
    s.displayShipStatus(ship, false);
    s.displayEventTxt(event_list.at(0).getText(), false);
    s.refreshW();
    getch();
}
