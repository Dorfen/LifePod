/*
** PROJECT, 2019
** LifePod
** File description:
** tests/test1.c
*/

#include <criterion/criterion.h>
#include "lifepod.h"

Test(is_event_loaded_test, event_is_null)
{
    cr_assert_eq(is_event_loaded(NULL), NULL);
}

Test(is_event_loaded_test, tab_is_null)
{
    event_t *event = malloc(sizeof(event_t));

    cr_assert_neq(event, NULL);
    event->system = 3;
    event->dmg = 4;
    event->max_mult = 3;
    event->tab = NULL;
    event->button = (void *)5;
    cr_assert_eq(is_event_loaded(event), false);
    free(event);
}

Test(is_event_loaded_test, button_is_null)
{
    event_t *event = malloc(sizeof(event_t));

    cr_assert_neq(event, NULL);
    event->system = 3;
    event->dmg = 4;
    event->max_mult = 3;
    event->tab = (void *)42;
    event->button = NULL;
    cr_assert_eq(is_event_loaded(event), false);
    free(event);
}

Test(is_event_loaded_test, system_is_low)
{
    event_t *event = malloc(sizeof(event_t));

    cr_assert_neq(event, NULL);
    event->system = 0;
    event->dmg = 3;
    event->max_mult = 3;
    event->tab = (void *)42;
    event->button = (void *)21;
    cr_assert_eq(is_event_loaded(event), false);
    free(event);
}

Test(is_event_loaded_test, system_is_high)
{
    event_t *event = malloc(sizeof(event_t));

    cr_assert_neq(event, NULL);
    event->system = 19;
    event->dmg = 4;
    event->max_mult = 3;
    event->tab = (void *)42;
    event->button = (void *)21;
    cr_assert_eq(is_event_loaded(event), false);
    free(event);
}

Test(is_event_loaded_test, dmg_is_low)
{
    event_t *event = malloc(sizeof(event_t));

    cr_assert_neq(event, NULL);
    event->system = 2;
    event->dmg = 0;
    event->max_mult = 3;
    event->tab = (void *)42;
    event->button = (void *)21;
    cr_assert_eq(is_event_loaded(event), false);
    free(event);
}

Test(is_event_loaded_test, max_mult_is_low)
{
    event_t *event = malloc(sizeof(event_t));

    cr_assert_neq(event, NULL);
    event->system = 2;
    event->dmg = 5;
    event->max_mult = 0;
    event->tab = (void *)42;
    event->button = (void *)21;
    cr_assert_eq(is_event_loaded(event), false);
    free(event);
}
