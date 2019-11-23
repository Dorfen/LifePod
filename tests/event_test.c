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

Test(parse_event_test, short_str)
{
    cr_assert_eq(parse_event("NULL"), NULL);
}

Test(parse_event_test, longer_str)
{
    cr_assert_eq(parse_event("hello:world:foo:bar:hello"), NULL);
}

Test(parse_event_test, empty_str)
{
    cr_assert_eq(parse_event(""), NULL);
}

Test(parse_event_test, wrong_str)
{
    cr_assert_eq(parse_event("hello:world:foo:bar"), NULL);
}

Test(parse_event_test, is_event_corectly_loaded)
{
    event_t *ret = parse_event("2\nButton3:2:2:2\nButton:2:2:2\nSome cryocell broke, resulting in loosing some colon.");

    cr_assert_not(ret ==  NULL);
    cr_assert_eq(ret->nb_buttons, 2);
    cr_assert_eq(ret->button[0]->system, 2);
    cr_assert_eq(ret->button[0]->dmg, 2);
    cr_assert_eq(ret->button[0]->max_mult, 2);
    cr_assert_str_eq(ret->button[0]->msg, "Button3");
    cr_assert_eq(ret->button[1]->system, 2);
    cr_assert_eq(ret->button[1]->dmg, 2);
    cr_assert_eq(ret->button[1]->max_mult, 2);
    cr_assert_str_eq(ret->button[1]->msg, "Button");
    cr_assert_str_eq(ret->tab[0], "Some cryocell broke, resulting in loosing some colon.");
}
