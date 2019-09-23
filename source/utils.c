/*
** EPITECH PROJECT, 2019
** LifePod
** File description:
** utils
*/

#include "lifepod.h"

void print_ship(WINDOW *win, int const y, int const x)
{
    if (y == -1 || x == -1)
        return;
    mvwprintw(win, y - 15, x - 65, "                    `. ___");
    mvwprintw(win, y - 14, x - 65, "                    __,' __`.                _..----....____");
    mvwprintw(win, y - 13, x - 65, "        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'");
    mvwprintw(win, y - 12, x - 65, "  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'");
    mvwprintw(win, y - 11, x - 65, ",'________________                          \\`-._`-','");
    mvwprintw(win, y - 10, x - 65, " `._              ```````````------...___   '-.._'-:");
    mvwprintw(win, y - 9, x - 65, "    ```--.._      ,.                     ````--...__\\-.");
    mvwprintw(win, y - 8, x - 65, "            `.--. `-`                       ____    |  |`");
    mvwprintw(win, y - 7, x - 65, "              `. `.                       ,'`````.  ;  ;`");
    mvwprintw(win, y - 6, x - 65, "                `._`.        __________   `.      \\'__/`");
    mvwprintw(win, y - 5, x - 65, "                   `-:._____/______/___/____`.     \\  `");
    mvwprintw(win, y - 4, x - 65, "                              |       `._    `.    \\");
    mvwprintw(win, y - 3, x - 65, "                               `._________`-.   `.   `.___");
    mvwprintw(win, y - 2, x - 65, "                                                  `------'`");
}
