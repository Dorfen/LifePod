/*
** PROJECT, 2018
** my_find_prime_sup
** File description:
** find prime
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    while (nb < 2147483647) {
        if (my_is_prime(nb))
            return (nb);
        nb = nb + 1;
    }
    return (0);
}
