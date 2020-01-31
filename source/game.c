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

int effect_button(ship_t *ship, event_t *event)
{
    int input = button_related(ship, event);

    if (ship == NULL || event == NULL || input == -1)
        return -1;
    if (input > event->nb_buttons)
        return 0;
    ship = apply_effect(ship, event->button[input - 1]);
    return 0;
}

int game(scr_t *scr, ship_t *ship, event_t **event)
{
    char c = 0;
    int val = 0;
    int coord[2] = {-1, -1};

    getmaxyx(scr->event, coord[0], coord[1]);
    while (c != OPT_QUIT) {
        wclear(scr->event);
        wclear(scr->cmd);
        scr->rebox_scr(scr);
        title_win(scr);
        print_ship(scr->event, coord[0], coord[1]);
        display_ship_status(scr->status, ship);
        val = rand() % (EVENT_NUM - 1);
        if (event_related(scr->event, scr->cmd, event[val]) != 0)
            break;
        refresh_all(scr);
        if (effect_button(ship, event[val]) == -1)
            break;
        if (ship->colon < 0) {
            exit_game();
            break;
        }
    }
    return 0;
}
