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

