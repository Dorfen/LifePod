/*
** EPITECH PROJECT, 2019
** LifePod
** File description:
** utils
*/

#include "lifepod.h"

void print_ship(WINDOW *win, coord_t const coord)
{
    mvwprintw(win, coord.y + 0, coord.x, "                    `. ___");
    mvwprintw(win, coord.y + 1, coord.x, "                    __,' __`.                _..----....____");
    mvwprintw(win, coord.y + 2, coord.x, "        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'");
    mvwprintw(win, coord.y + 3, coord.x, "  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'");
    mvwprintw(win, coord.y + 4, coord.x, ",'________________                          \\`-._`-','");
    mvwprintw(win, coord.y + 5, coord.x, " `._              ```````````------...___   '-.._'-:");
    mvwprintw(win, coord.y + 6, coord.x, "    ```--.._      ,.                     ````--...__\\-.");
    mvwprintw(win, coord.y + 7, coord.x, "            `.--. `-`                       ____    |  |`");
    mvwprintw(win, coord.y + 8, coord.x, "              `. `.                       ,'`````.  ;  ;`");
    mvwprintw(win, coord.y + 9, coord.x, "                `._`.        __________   `.      \\'__/`");
    mvwprintw(win, coord.y + 10, coord.x, "                   `-:._____/______/___/____`.     \\  `");
    mvwprintw(win, coord.y + 11, coord.x, "                              |       `._    `.    \\");
    mvwprintw(win, coord.y + 12, coord.x, "                               `._________`-.   `.   `.___");
    mvwprintw(win, coord.y + 13, coord.x,"                                                  `------'`");
}

int damage_ship(ship_t *ship, int const dmg, int const sys)
{
    switch(sys) {
    case (0): ship->colon -= dmg * 10; break;
    case (1): ship->scan->atm -= dmg; break;
    case (2): ship->scan->grav -= dmg; break;
    case (3): ship->scan->temp -= dmg; break;
    case (4): ship->scan->water -= dmg; break;
    case (5): ship->scan->res -= dmg; break;
    case (6): ship->landing -= dmg; break;
    case (7): ship->build -= dmg; break;
    default: break;
    }
    return (0);
}
