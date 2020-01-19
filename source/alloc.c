/*
** PROJECT, 2019
** lifepod
** File description:
** alloc
*/

#include "lifepod.h"

scan_t *alloc_scan(void)
{
    scan_t *ret = malloc(sizeof(scan_t));

    if (ret == NULL)
        return (NULL);
    ret->atm = 100;
    ret->grav = 100;
    ret->temp = 100;
    ret->water = 100;
    ret->res = 100;
    return (ret);
}

ship_t *alloc_ship(void)
{
    ship_t *ret = malloc(sizeof(ship_t));
    scan_t *scan = alloc_scan();

    if (ret == NULL || scan == NULL)
        return (NULL);
    ret->colon = 1000;
    ret->scan = scan;
    ret->landing = 100;
    ret->build = 100;
    return (ret);
}

event_t *alloc_event(void)
{
    event_t *ret = malloc(sizeof(event_t));

    if (ret == NULL)
        return (NULL);
    ret->tab = NULL;
    ret->nb_buttons = 0;
    ret->button = NULL;
    return (ret);
}

button_t *alloc_button(void)
{
    button_t *ret = malloc(sizeof(button_t));

    if (ret == NULL)
        return NULL;
    ret->system = 0;
    ret->dmg = 0;
    ret->max_mult = 1;
    ret->msg = NULL;
    return ret;
}
