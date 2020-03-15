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

    srand(time(NULL));
    while (ship.getColon() > 0) {
        Screen s;

        //s.displayShipStatus(ship, false);
        //try {
        //    s.displayEventTxt(event_list.at(event_nbr).getText(), true);
        //    if (event_list.at(event_nbr).pressButtons(s, ship))
        //        event_nbr = rand() % event_list.size();
        //} catch (const std::out_of_range &oor) {
        //    s.cmd_ << "Error: invalid event number.";
        //    continue;
        //} catch (const EventErr &err) {
        //    if (err.getMessage() == "Quit")
        //        break;
        //    else
        //        throw;
        //}
    }
    if (ship.getColon() <= 0)
        std::cout << "You lose, all your colons dies" << std::endl;
}
