/*
** EPITECH PROJECT, 2019
** LifePod
** File description:
** source/event.c
*/

#include "lifepod.h"

int button(WINDOW *cmd, const char *tab[])
{
    const coord_t coord = {4 * COLS / 4, 2 * LINES / 8 + 1};
    int e = 0;
    int c = 0;

    wbrefresh(cmd, ACS_VLINE, ACS_HLINE);
    for (int i = coord.x / 4; i < coord.x - 1 && e < 3; i += (coord.x / 4)) {
        for (int j = 1; j < coord.y - 1; j++)
            mvwaddch(cmd, j, i, ACS_VLINE);
        mvwprintw(cmd, coord.y / 2, (i - (coord.x / 4) / 2) -
                  (strlen(tab[e]) / 2), "%s", tab[e]);
        e++;
    }
    wrefresh(cmd);
    for (;;) {
        c = getch();
        switch (c) {
        case ('q'): return (0);
        case ('a'): return (1);
        case ('z'): return (2);
        case ('e'): return (3);
        }
    }
    return (0);
}

int event(scr_t *scr, ship_t *ship)
{
    //int random = rand() % MAX_EVENT;

/*switch (random) {
    case(1): event_1(scr, ship); return(1);
    case(2): event_2(scr, ship); return(2);
    default: return(0);
    }*/
    event_1(scr, ship);
    return (0);
}
