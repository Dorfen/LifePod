/*
** PROJECT, 2018
** my_put_str_array.c
** File description:
** show word array
*/

#include "my.h"

int my_put_str_array(char **tab)
{
    unsigned int lenght = my_tablen(tab);

    for (unsigned int i = 0; i < lenght; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
