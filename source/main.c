/*
** PROJECT, 2019
** lifepod
** File description:
** poosd
*/

#include "lifepod.h"

static void freedom(event_t **event, ship_t *ship, scr_t *scr)
{
    if (event == NULL || ship == NULL || scr == NULL)
        return;
    scr->remove_win(scr);
    free(scr);
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
        goto FREE_EXIT;
    if (init_screen() == -1)
        goto FREE_EXIT;
    scr = new_scr();
    if ((event = load_all_event()) == NULL)
        goto FREE_EXIT;
    if (game(scr, ship, event) != 0)
        goto FREE_EXIT;
    endwin();
    END_FREE:freedom(event, ship, scr);
    return (exit);
    FREE_EXIT: exit = 84;
    goto END_FREE;
}
