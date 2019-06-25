/*
** PROJECT, 2018
** my_strncat.c
** File description:
** cat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);
    int i = 0;

    while (i < nb && src[i]) {
        dest[len + 1] = src[i];
    }
    dest[len + i] = '\0';
    return (dest);
}
