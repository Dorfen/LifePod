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

    wrefresh(scr->event);
    refresh();
    while (c != 'q') {
        mvwprintw(scr->event, 2, 2, "%s", "HELLO");
        refresh();
        c = getch();
    }
    endwin();
    free(scr);
    return (0);
}
