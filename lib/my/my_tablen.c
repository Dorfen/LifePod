/*
** PROJECT, 2018
** my_tablen.c
** File description:
** tablen
*/

#include "my.h"

int my_tablen(char const * const *tab)
{
    int x = 0;

    if (tab == NULL)
        return -1;
    while (tab[x] != NULL) {
        x = x + 1;
    }
    return (x);
}
