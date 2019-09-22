/*
** EPITECH PROJECT, 2019
** parser
** File description:
** lib/parser/is_separated.c
*/

#include "parser.h"

int is_separated(char const *str, char const *c, int const j)
{
    if (str == NULL || c == NULL)
        return (-1);
    if ((size_t)j > strlen(str))
        return (-1);
    if (j > 0)
        if (str[j - 1] == '\\')
            return (0);
    for (int i = 0; c[i] != '\0'; i++)
        if (str[j] == c[i])
            return (1);
    return (0);
}
