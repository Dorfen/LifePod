/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** put nbr
*/

#include "my.h"

void my_put_nbr(long long nb)
{
    long long num;

    if (nb < 0) {
        my_putchar(45);
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            num = nb % 10;
            nb = nb - num;
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar(48 + num);
        }
        else
            my_putchar(48 + nb);
    }
}
