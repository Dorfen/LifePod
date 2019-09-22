/*
** EPITECH PROJECT, 2019
** LifePod
** File description:
** utils
*/

#include "lifepod.h"

void print_ship(WINDOW *win, int const y, int const x)
{
    mvwprintw(win, y - 15, x - 64, "                    `. ___");
    mvwprintw(win, y - 14, x - 64, "                    __,' __`.                _..----....____");
    mvwprintw(win, y - 13, x - 64, "        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'");
    mvwprintw(win, y - 12, x - 64, "  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'");
    mvwprintw(win, y - 11, x - 64, ",'________________                          \\`-._`-','");
    mvwprintw(win, y - 10, x - 64, " `._              ```````````------...___   '-.._'-:");
    mvwprintw(win, y - 9, x - 64, "    ```--.._      ,.                     ````--...__\\-.");
    mvwprintw(win, y - 8, x - 64, "            `.--. `-`                       ____    |  |`");
    mvwprintw(win, y - 7, x - 64, "              `. `.                       ,'`````.  ;  ;`");
    mvwprintw(win, y - 6, x - 64, "                `._`.        __________   `.      \\'__/`");
    mvwprintw(win, y - 5, x - 64, "                   `-:._____/______/___/____`.     \\  `");
    mvwprintw(win, y - 4, x - 64, "                              |       `._    `.    \\");
    mvwprintw(win, y - 3, x - 64, "                               `._________`-.   `.   `.___");
    mvwprintw(win, y - 2, x - 64, "                                                  `------'`");
}
