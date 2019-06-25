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
    scr_t *screen = build_scr_t();

    if (ship == NULL)
        return (84);
    if (init_screen() == -1)
        return (84);
    if (game(screen, ship) != 0)
        return (84);
    free(screen);
    free(ship->scan);
    free(ship);
    return (0);
}
