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

Test(alloc_tests, alloc_event_struct)
{
    event_t *foo = alloc_event();

    cr_assert_not(foo == NULL);
    cr_assert(foo->tab == NULL);
    cr_assert(foo->nb_buttons == 0);
    cr_assert(foo->button == NULL);
    free(foo);
}

Test(alloc_tests, alloc_button_struct)
{
    button_t *foo = alloc_button();

    cr_assert_not(foo == NULL);
    cr_assert(foo->system == 0);
    cr_assert(foo->dmg == 0);
    cr_assert(foo->max_mult == 1);
}

Test(alloc_tests, alloc_screen_struct)
{
    scr_t *foo = build_scr_t();

    cr_assert_not(foo == NULL);
    free(foo);
}
