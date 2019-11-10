/*
** PROJECT, 2019
** LifePod
** File description:
** tests/handle_button_test.c
*/

#include <criterion/criterion.h>
#include "lifepod.h"

Test(handle_button, ship_is_null)
{
    event_t *val = alloc_event();
    cr_assert_eq(button_related(NULL, val), 84);
    free(val);
}

Test(handle_button, event_is_null)
{
    ship_t *val = alloc_ship();
    cr_assert_eq(button_related(val, NULL), 84);
    free(val);
}
