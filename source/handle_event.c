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
    return true;
}

int event_related(WINDOW *win, WINDOW *cmd, event_t *event)
{
    int coord[2] =  {-1, -1};

    getmaxyx(cmd, coord[0], coord[1]);
    if (win == NULL || is_event_loaded(event) == false)
        return 1;
    for (int i = 0; event->tab[i] != NULL; i++)
        mvwprintw(win, 3 + i, 3, event->tab[i]);
    for (int i = 0; event->button[i] != NULL; i++) {
        mvwprintw(cmd, coord[0] / 2, coord[1] * i / event->nb_buttons + event->nb_buttons, event->button[i]->msg);
    }
    return 0;
}

