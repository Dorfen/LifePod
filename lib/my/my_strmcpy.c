/*
** EPITECH PROJECT, 2018
** lib my
** File description:
** cat from
*/

#include "my.h"

char *my_strmcpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; dest[i] != '\0' || src[n] != '\0'; n++) {
        dest[i] = src[n];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
