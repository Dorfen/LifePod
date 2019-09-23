/*
** PROJECT, 2019
** LifePod
** File description:
** source/handle_event.c
*/

#include "lifepod.h"

int event_related(WINDOW *win, event_t **event)
{
    if (win == NULL || event == NULL)
        return 1;
    mvwprintw(win, 3, 3, event[0]->msg);
    mvwprintw(win, 4, 3, event[1]->msg);
    return 0;
}
