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

    srand(time(NULL));
    if (ship == NULL)
        return (84);
    //if (init_screen() == -1)
    //    return (84);
    //if (game(ship) != 0)
    //    return (84);
    load_all_event();
    free(ship->scan);
    free(ship);
    return (0);
}
