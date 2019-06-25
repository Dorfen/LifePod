/*
** PROJECT, 2018
** my_char_isnum.c
** File description:
** is num
*/

#include "my.h"

int my_char_isnum(char const c)
{
    if (c != '\0') {
        if (c >= '0' && c <= '9')
            return (1);
    }
    return (0);
}
