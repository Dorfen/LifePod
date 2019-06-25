/*
** PROJECT, 2018
** my_str_isnum.c
** File description:
** is num
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;
    int c = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            c = c + 1;
        i = i + 1;
    }
    if (i == c)
        return (1);
    else
        return (0);
}
