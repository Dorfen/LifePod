/*
** PROJECT, 2019
** LifePod
** File description:
** tests/alloc_tests.c
*/

#include "lifepod.h"
#include <criterion/criterion.h>

Test(alloc_tests, alloc_scan_struct)
{
    scan_t *foo = alloc_scan();

    cr_assert_not(foo == NULL);
    cr_assert(foo->atm == 100);
    cr_assert(foo->grav == 100);
    cr_assert(foo->temp == 100);
    cr_assert(foo->water == 100);
    cr_assert(foo->res == 100);
    free(foo);
}

Test(alloc_tests, alloc_ship_struct)
{
    ship_t *foo = alloc_ship();

    cr_assert_not(foo == NULL);
    cr_assert_not(foo->scan == NULL);
    cr_assert(foo->colon == 1000);
    cr_assert(foo->landing == 100);
    cr_assert(foo->build == 100);
    free(foo->scan);
    free(foo);
}

Test(alloc_tests, alloc_screen_struct)
{
    scr_t *foo = build_scr_t();

    cr_assert_not(foo == NULL);
    free(foo);
}
