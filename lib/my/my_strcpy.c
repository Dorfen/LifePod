/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** cpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    unsigned int n = 0;

    while (n < my_strlen(src)) {
        dest[n] = src[n];
        n = n + 1;
    }
    dest[my_strlen(src)] = '\0';
    return (dest);
}
