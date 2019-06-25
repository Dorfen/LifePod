/*
** PROJECT, 2019
** libmy
** File description:
** fill str with '\0'
*/

#include "../../include/my.h"

char *my_str_filler(char *str, int size)
{
    if (str == NULL)
        str = malloc(sizeof(char) * (size));
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}
