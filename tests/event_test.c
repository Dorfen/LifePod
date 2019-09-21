/*
** PROJECT, 2019
** LifePod
** File description:
** tests/alloc_tests.c
*/

#include "lifepod.h"
#include <criterion/criterion.h>

Test(parse_event_test, str_is_null)
{
    cr_assert_eq(parse_event(NULL), NULL);
}

Test(parse_event_test, is_event_corectly_loaded)
{
    event_t *ret = parse_event("1:10:5:Some cryocell broke, resulting in loosing some colon.");

    cr_assert_eq(ret->system, COLON);
    cr_assert_eq(ret->dmg, 10);
    cr_assert_eq(ret->max_mult, 5);
    cr_assert_str_eq(ret->msg, "Some cryocell broke, resulting in loosing some colon.");
    free(ret->msg);
    free(ret);
}
