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
    int turn = 0;
    char c = 0;

    while (c != 'q') {
        display_ship_status(scr->status, ship);
        //if (turn %2 == 1)
        event(scr, ship);
        refresh();
        c = getch();
    }
    endwin();
    free(scr);
    return (turn);
}
