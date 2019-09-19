/*
** PROJECT, 2019
** LifePod
** File description:
** source/free_struct.c
*/

#include "lifepod.h"

void free_event(event_t **event)
{
    if (event == NULL)
        return;
    for (int i = 0; event[i] != NULL; i++) {
        if (event[i]->msg != NULL)
            free(event[i]->msg);
        free(event[i]);
    }
    free(event);
}
