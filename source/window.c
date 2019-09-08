/*
** PROJECT, 2019
** LifePod
** File description:
** window
*/

#include "lifepod.h"

int display_ship_status(WINDOW *status, ship_t *ship)
{
    wclear(status);
    wbrefresh(status, ACS_VLINE, ACS_HLINE);
    load_bar(status, "Colons", (coord_t){1, 1}, (int[2]){ship->colon, 1000});
    load_bar(status, "Landing", (coord_t){1, 4}, (int[2]){ship->landing, 100});
    load_bar(status, "Building", (coord_t){1, 7}, (int[2]){ship->build, 100});
    mvwprintw(status, 10, 1, "Scanners status:");
    load_bar(status, "Athmosphere", (coord_t){1, 11}, (int[2]){ship->scan->atm, 100});
    load_bar(status, "Gravity", (coord_t){1, 14}, (int[2]){ship->scan->grav, 100});
    load_bar(status, "Temperature", (coord_t){1, 17}, (int[2]){ship->scan->temp, 100});
    load_bar(status, "Water", (coord_t){1, 20}, (int[2]){ship->scan->water, 100});
    load_bar(status, "Ressources", (coord_t){1, 23}, (int[2]){ship->scan->res, 100});
    wrefresh(status);
    return (0);
}

