/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** copy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, unsigned int n)
{
    unsigned int i = 0;

    while (i < n && i < my_strlen(src)) {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
