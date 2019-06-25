/*
** EPITECH PROJECT, 2018
** my_strcapitalize.c
** File description:
** cap
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int x = 0;

    while (str[x] != '\n') {
        while (str[x - 1] != 32) {
            x = x + 1;
        }
        if ((str[x] >= 'a') && (str[x] <= 'z')) {
            str[x] = str[x] - 32;
        }
    }
    return (str);
}
