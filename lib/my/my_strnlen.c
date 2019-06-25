/*
** PROJECT, 2018
** my_strnlen
** File description:
** strlen
*/

#include "my.h"

int my_strnlen(char const *str, int n)
{
    int x = 0;

    while (n > x && str[x] != '\0') {
        x = x + 1;
    }
    return (x);
}
