/*
** PROJECT, 2019
** LifePod
** File description:
** window
*/

#include "lifepod.h"

inline void refresh_all(scr_t *scr)
{
    wrefresh(scr->cmd);
    wrefresh(scr->status);
    wrefresh(scr->event);
    refresh();
}

inline void title_win(scr_t *scr)
{
    mvwprintw(scr->event, 0, 1, "Logs");
    mvwprintw(scr->cmd, 0, 1, "Answer");
    mvwprintw(scr->status, 0, 1, "Status");
}

void display_ship_status(WINDOW *status, ship_t *ship)
{
    wclear(status);
    box(status, ACS_VLINE, ACS_HLINE);
    load_bar(status, "Colons", (coord_t){1, 1}, (int[2]){ship->colon, 1000});
    mvwprintw(status, 3, 1, "%04i | 1000", ship->colon);
    load_bar(status, "Landing", (coord_t){1, 5}, (int[2]){ship->landing, 100});
    mvwprintw(status, 7, 1, "%03i | 100", ship->landing);
    load_bar(status, "Building", (coord_t){1, 9}, (int[2]){ship->build, 100});
    mvwprintw(status, 11, 1, "%03i | 100", ship->build);
    mvwprintw(status, 15, 1, "Scanners status:");
    load_bar(status, "Athmosphere", (coord_t){1, 16}, (int[2]){ship->scan->atm, 100});
    mvwprintw(status, 18, 1, "%03i | 100", ship->scan->atm);
    load_bar(status, "Gravity", (coord_t){1, 20}, (int[2]){ship->scan->grav, 100});
    mvwprintw(status, 22, 1, "%03i | 100", ship->scan->grav);
    load_bar(status, "Temperature", (coord_t){1, 24}, (int[2]){ship->scan->temp, 100});
    mvwprintw(status, 26, 1, "%03i | 100", ship->scan->temp);
    load_bar(status, "Water", (coord_t){1, 28}, (int[2]){ship->scan->water, 100});
    mvwprintw(status, 30, 1, "%03i | 100", ship->scan->water);
    load_bar(status, "Ressources", (coord_t){1, 32}, (int[2]){ship->scan->res, 100});
    mvwprintw(status, 34, 1, "%03i | 100", ship->scan->res);
}
