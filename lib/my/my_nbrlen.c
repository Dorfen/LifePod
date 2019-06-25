/*
** EPITECH PROJECT, 2018
** my_nbrlen
** File description:
** return nbr len
*/

#include "my.h"

int my_nbrlen(int nb)
{
    int i = 0;
    int nbr = nb;

    for (; nbr != 0; i++) {
        nbr = nbr / 10;
    }
    return (i);
}
