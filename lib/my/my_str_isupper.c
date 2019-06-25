/*
** PROJECT, 2018
** my_str_isupper
** File description:
** is uppe
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0'){
        if (str[i] >= 'A' && str[i] <= 'Z')
            return (1);
        else
            return (0);
        i = i + 1;
    }
    return (0);
}
