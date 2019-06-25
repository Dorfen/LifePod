/*
** PROJECT, 2019
** lifepod
** File description:
** poosd
*/

#include "lifepod.h"

int main(void)
{
    ship_t *ship = alloc_ship();

    if (ship == NULL)
        return (84);
    free(ship->scan);
    free(ship);
    return (0);
}
