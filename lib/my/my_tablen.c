/*
** EPITECH PROJECT, 2018
** my_tablen.c
** File description:
** tablen
*/

#include "my.h"

int my_tablen(char **tab)
{
    int x = 0;

    while (tab[x] != NULL) {
        x = x + 1;
    }
    return (x);
}
