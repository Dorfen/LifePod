/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** strlen
*/

#include "my.h"

unsigned int my_strlen(char const *str)
{
    unsigned int x = 0;

    while (str[x] != '\0' || str[x] != 0) {
        x = x + 1;
    }
    return (x);
}
