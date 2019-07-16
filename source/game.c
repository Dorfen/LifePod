/*
** PROJECT, 2019
** LifePod
** File description:
** game.c
*/

#include "lifepod.h"

void exit_game(void)
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
    int turn = 0;
    char c = 0;

    while (c != 'q') {
        display_ship_status(scr->status, ship);
        //if (turn %2 == 1)
        event(scr, ship);
        refresh();
        if (ship->colon <= 0) {
            exit_game();
            break;
        }
        c = getch();
    }
    endwin();
    free(scr);
    return (turn);
}
