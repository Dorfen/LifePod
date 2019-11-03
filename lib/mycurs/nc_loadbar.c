/*
** PROJECT, 2019
** mycurs
** File description:
** loadbar
*/

#include "my_curse.h"

void load_bar(WINDOW *box, char const *name, coord_t const coord, int value[2])
{
    int bar_size = getmaxx(box) - 4;
    char *bar_load = malloc(sizeof(char) * (bar_size + 1));

    bar_load[bar_size] = '\0';
    for (int i = 0; i < bar_size; i++)
        bar_load[i] = '-';
    value[0] = (value[0] * bar_size) / value[1];
    for (int i = 0; i <= value[0] && bar_load[i] != '\0'; i++)
        bar_load[i] = '#';
    mvwprintw(box, coord.y, coord.x, "%s:", name);
    mvwprintw(box, coord.y + 1, coord.x, "[%s]", bar_load);
    free(bar_load);
}
