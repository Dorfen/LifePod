/*
** PROJECT, 2019
** lifepd
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
