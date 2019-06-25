/*
** EPITECH PROJECT, 2018
** my_str_isalpha.c
** File description:
** is alpha
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;
    int c = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))
            c = c + 1;
        i = i + 1;
    }
    if (i == c)
        return (1);
    else
        return (0);
}
