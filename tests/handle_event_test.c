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
    cr_assert_eq(is_event_loaded(NULL), false);
}

Test(is_event_loaded_test, tab_is_null)
{
    event_t *event = malloc(sizeof(event_t));

    cr_assert_neq(event, NULL);
    event->tab = NULL;
    event->button = (void *)5;
    cr_assert_eq(is_event_loaded(event), false);
    free(event);
}

Test(is_event_loaded_test, button_is_null)
{
    event_t *event = malloc(sizeof(event_t));

    cr_assert_neq(event, NULL);
    event->tab = (void *)42;
    event->button = NULL;
    cr_assert_eq(is_event_loaded(event), false);
    free(event);
}

Test(is_event_loaded_test, all_pointer)
{
    event_t *event = malloc(sizeof(event_t));

    cr_assert_neq(event, NULL);
    event->tab = (void *)42;
    event->button = (void *)21;
    cr_assert_eq(is_event_loaded(event), true);
    free(event);
}
