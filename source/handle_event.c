/*
** PROJECT, 2019
** LifePod
** File description:
** source/handle_event.c
*/

#include "lifepod.h"

bool is_event_loaded(event_t *event)
{
    if (event == NULL)
        return false;
    if (event->tab == NULL || event->button == NULL)
        return false;
    if (event->system < 1 || event->system > 8)
        return false;
    if (event->dmg < 1 || event->max_mult < 1)
        return false;
    return true;
}

int event_related(WINDOW *win, WINDOW *cmd, event_t *event)
{
    int size = -1;
    int coord[2] =  {-1, -1};

    getmaxyx(cmd, coord[0], coord[1]);
    if (win == NULL || is_event_loaded(event) == false)
        return 1;
    for (int i = 0; event->tab[i] != NULL; i++)
        mvwprintw(win, 3 + i, 3, event->tab[i]);
    size = my_tablen((char const *const *)event->button);
    for (int i = 0; event->button[i] != NULL; i++) {
        mvwprintw(cmd, coord[0] / 2, coord[1] * i / size + size, event->button[i]);
    }
    return 0;
}
