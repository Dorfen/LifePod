/*
** PROJECT, 2019
** LifePod
** File description:
** game.c
*/

#include "lifepod.h"

int game(ship_t *ship)
{
    scr_t *scr = build_scr_t();
    char c = 0;

    while (c != 'q') {
        display_ship_status(scr->status, ship);
        refresh();
        c = getch();
    }
    endwin();
    free(scr);
    return (0);
}
