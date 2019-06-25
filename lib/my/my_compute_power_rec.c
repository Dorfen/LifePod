/*
** PROJECT, 2018
** my compute power it
** File description:
** is working
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int result = 1;

    if (p > 0)
        result = nb * my_compute_power_rec(nb, p - 1);
    else
        return (1);
    return (result);
}
