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

void free_button(button_t **but)
{
    if (but == NULL)
        return;
    for (int i = 0; but[i] != NULL; i++) {
        free(but[i]->msg);
        free(but[i]);
    }
    free(but);
}

void free_event(event_t **event)
{
    if (event == NULL)
        return;
    for (int i = 0; event[i] != NULL; i++) {
        if (event[i]->tab != NULL)
            free_tab(event[i]->tab);
        if (event[i]->button != NULL)
            free_button(event[i]->button);
        free(event[i]);
    }
    free(event);
}
