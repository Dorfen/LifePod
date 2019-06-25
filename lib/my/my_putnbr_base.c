/*
** PROJECT, 2018
** my_putnbr_base.c
** File description:
** nuber base
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int a;

    a = my_strlen(base);
    if (nbr < 0){
        nbr = nbr * -1;
        my_putchar('-');
    }
    if (nbr == 0)
        return (0);
    else
        my_putnbr_base((nbr / a), base);
    my_putchar(base[nbr % a]);
    return (0);
}
