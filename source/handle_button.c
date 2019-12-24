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

static int compute_dmg(const button_t *button)
{
    int mult = 0;
    int dmg = 0;

    if (button == NULL) {
        fprintf(stderr, "Button is null\n");
        return -1;
    }
    fprintf(stderr, "Damage : %i * %i\n", button->dmg, button->max_mult);
    dmg = rand() % button->dmg;
    mult = rand() % button->max_mult;
    return dmg * mult;
}

ship_t *apply_effect(ship_t *ship, const button_t *button)
{
    int val = compute_dmg(button);

    if (val == -1)
        return (ship);
    switch (button->system) {
        case COLON:
            ship->colon -= val;
            break;
        case ATM:
            ship->scan->atm -= val;
            break;
        case GRAV:
            ship->scan->grav -= val;
            break;
        case TEMP:
            ship->scan->temp -= val;
            break;
        case WATER:
            ship->scan->water -= val;
            break;
        case RES:
            ship->scan->res -= val;
            break;
        case LAND:
            ship->landing -= val;
            break;
        case BUILD:
            ship->build -= val;
            break;
        default:
            break;
    }
    return ship;
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
