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
    scr_t *scr = build_scr_t();
    char c = 0;
    int y = 0;
    int x = 0;

    while (c != 'q') {
        title_win(scr);
        getmaxyx(scr->event, y, x);
        print_ship(scr->event, y, x);
        display_ship_status(scr->status, ship);
        refresh_all(scr);
        c = getch();
    }
    endwin();
    free(scr);
    return (0);
}
