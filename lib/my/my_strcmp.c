/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** cmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 == *s2++)
        if (*s1++== 0)
            return (0);
    return (*(unsigned char *) s1 - *(unsigned char *) --s2);
}
