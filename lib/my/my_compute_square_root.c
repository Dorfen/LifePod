/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** squre_root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int r = 1;

    if (nb <= 0 || nb > 2147483647)
        return (0);
    while (nb != r * r) {
        if (r > 153695)
            return (0);
        r = r + 1;
    }
    return (r);
}
