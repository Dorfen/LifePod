/*
** PROJECT, 2019
** LifePod
** File description:
** tests/handle_button_test.c
*/

#include <criterion/criterion.h>
#include "lifepod.h"

Test(button_related, ship_is_null)
{
    event_t *val = alloc_event();
    cr_assert_eq(button_related(NULL, val), -1);
    free(val);
}

Test(button_related, event_is_null)
{
    ship_t *val = alloc_ship();
    cr_assert_eq(button_related(val, NULL), -1);
    free(val);
}

Test(handle_button, tab_len_too_large)
{
    cr_assert_eq(is_good_input(5, '\0'), false);
}
