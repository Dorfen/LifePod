/*
** PROJECT, 2019
** LifePod
** File description:
** game.c
*/

#include "lifepod.h"

static void exit_game(void)
{
    const char msg[] = "You lose, all your colon have died.";

    clear();
    refresh();
    mvprintw(LINES/2, COLS/2 - strlen(msg), msg);
    getch();
}

int game(ship_t *ship)
{
    //scr_t *scr = build_scr_t();

    //free(scr);
    return (0);
}
