/*
** PROJECT, 2019
** LifePod
** File description:
** source/free_struct.c
*/

#include "lifepod.h"

void free_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_event(event_t **event)
{
    if (event == NULL)
        return;
    for (int i = 0; event[i] != NULL; i++) {
        if (event[i]->tab != NULL)
            free_tab(event[i]->tab);
        free(event[i]);
    }
    free(event);
}
