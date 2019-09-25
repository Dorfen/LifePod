/*
** PROJECT, 2019
** LifePod
** File description:
** source/handle_event.c
*/

#include "lifepod.h"

int event_related(WINDOW *win, event_t *event, char const input, ship_t *ship)
{
    if (win == NULL || event == NULL || event->tab == NULL)
        return 1;
    for (int i = 0; event->tab[i] != NULL; i++) {
        mvwprintw(win, 3 + i, 3, event->tab[i]);
    }
    return 0;
}
