/*
** EPITECH PROJECT, 2018
** my_put_float
** File description:
** display flot
*/

#include "my.h"

void my_put_float(float nb)
{
    int nb_int = (int) nb;

    my_put_nbr(nb_int);
    my_putchar('.');
    nb = (nb - nb_int) * 1000000;
    my_put_nbr(nb);
    if (nb < 10)
        my_put_nbr(0);
}
