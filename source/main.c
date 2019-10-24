/*
** PROJECT, 2019
** lifepod
** File description:
** poosd
*/

#include "lifepod.h"

static void freedom(event_t **event, ship_t *ship)
{
    if (event == NULL || ship == NULL)
        return;
    free_event(event);
    free(ship->scan);
    free(ship);
}

int main(void)
{
    int exit = 0;
    scr_t *scr = NULL;
    ship_t *ship = alloc_ship();
    event_t **event = NULL;

    srand(time(NULL));
    if (ship == NULL)
        exit = 84;
    if (init_screen() == -1)
        exit = 84;
    scr = build_scr_t();
    if ((event = load_all_event()) == NULL)
        exit = 84;
    if (game(scr, ship, event) != 0)
        exit = 84;
    endwin();
    freedom(event, ship);
    return (exit);
}
