/*
** EPITECH PROJECT, 2018
** atoi
** File description:
** convert char -> int
*/

#include "my.h"

int my_atoi(char *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0' && my_char_isnum(str[i]) == 1; i++)
        res = res * 10 + (str[i] - '0');
    return (sign * res);
}
