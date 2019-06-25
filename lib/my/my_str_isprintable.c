/*
** EPITECH PROJECT, 2018
** my_str_isprintable
** File description:
** pritable
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0'){
        if (str[i] >= 32 && str[i] <= 126)
            return (1);
        else
            return (0);
        i = i + 1;
    }
    return (84);
}

int my_ispritable(char const c)
{

    if (c >= 32 && c <= 126)
        return (1);
    else
        return (0);
}
