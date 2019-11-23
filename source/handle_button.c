/*
** PROJECT, 2019
** LifePod
** File description:
** source/handle_button.c
*/

#include "lifepod.h"

bool is_good_input(unsigned int nb_buttons, char input)
{
    if (nb_buttons > 4)
        return false;
    switch (input) {
        case OPT_ONE:
        case OPT_TWO:
        case OPT_THREE:
        case OPT_FOUR:
        case OPT_QUIT:
            return true;
        default:
            return false;
    }
}

int button_related(ship_t *ship, event_t *event)
{
    char c = 0;

    if (ship == NULL || event == NULL || event->nb_buttons == 0)
        return -1;
    while (is_good_input(event->nb_buttons, c) == false)
        c = getch();
    switch (c) {
        case OPT_ONE:
            return 1;
        case OPT_TWO:
            return 2;
        case OPT_THREE:
            return 3;
        case OPT_FOUR:
            return 4;
        default:
            return -1;
    }
    return -1;
}
