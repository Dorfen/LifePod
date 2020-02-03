#include "Ship.hpp"
#include "Screen.hpp"

int main(void)
{
    Screen s;
    Ship ship;

    s.printShip();
    s.displayShipStatus(ship);
    getch();
}
