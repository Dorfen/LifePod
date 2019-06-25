/*
** EPITECH PROJECT, 2018
** my_showstr.c
** File description:
** show str
*/

#include "my.h"

int my_showstr(char const *str)
{
    int i;

    i = 0;
    while (str[i]){
        if (my_isprintable(str[i]) != 0)
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            my_putnbr_base(str[i], "0123456789abcdef");
        }
        i = i + 1;
    }
    return (0);
}
