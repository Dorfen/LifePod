/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** dup str
*/

#include "my.h"

char *my_strdup(char *str)
{
    char *out = malloc(sizeof(char) * (my_strlen(str) + 1));

    out = my_strcpy(out, str);
    out[my_strlen(str)] = '\0';
    return (out);
}
