/*
** PROJECT, 2019
** lifepod
** File description:
** poosd
*/

#include "lifepod.h"

int main(void)
{
    int exit = 0;
    ship_t *ship = alloc_ship();
    event_t **event = NULL;

    srand(time(NULL));
    if (ship == NULL)
        return (84);
    //if (init_screen() == -1)
    //    return (84);
    //if (game(ship) != 0)
    //    return (84);
    if ((event = load_all_event()) == NULL)
        exit = 84;
    free_event(event);
    free(ship->scan);
    free(ship);
    return (exit);
}
