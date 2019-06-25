/*
** PROJECT, 2018
** my_str_islower.c
** File description:
** is lower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0'){
        if (str[i] >= 'a' && str[i] <= 'z')
            return (1);
        else
            return (0);
        i = i + 1;
    }
    return (84);
}
