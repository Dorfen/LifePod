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

int game(scr_t *scr, ship_t *ship, event_t **event)
{
    char c = 0;
    int coord[2] = {0, 0};

    getmaxyx(scr->event, coord[0], coord[1]);
    while (c != 'q') {
        title_win(scr);
        print_ship(scr->event, coord[0], coord[1]);
        display_ship_status(scr->status, ship);
        if (event_related(scr->cmd, event) != 0)
            return 84;
        if (ship->colon == 0) {
            exit_game();
            break;
        }
        refresh_all(scr);
        c = getch();
    }
    free(scr);
    return 0;
}
