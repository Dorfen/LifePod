/*
** PROJECT, 2019
** LifePod
** File description:
** source/game.c
*/

#include "lifepod.h"

static void exit_game(void)
{
    const char msg[] = "You lose, all your colon have died.";

    clear();
    mvprintw(LINES/2, COLS/2 - (strlen(msg) / 2), msg);
    refresh();
    getch();
}

int game(scr_t *scr, ship_t *ship, event_t **event)
{
    char c = 0;
    int coord[2] = {-1, -1};

    getmaxyx(scr->event, coord[0], coord[1]);
    while (c != OPT_QUIT) {
        title_win(scr);
        print_ship(scr->event, coord[0], coord[1]);
        display_ship_status(scr->status, ship);
        if (event_related(scr->event, scr->cmd, event[0]) != 0)
            break;
        refresh_all(scr);
        if (button_related(ship, event[0]) == -1)
            break;
        else
            ship->colon -= 100;
        if (ship->colon == 0) {
            exit_game();
            break;
        }
    }
    free(scr);
    return 0;
}
