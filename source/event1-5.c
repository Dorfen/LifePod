/*
** PROJECT, 2019
** LifePod
** File description:
** event 1-5
*/

#include "lifepod.h"

int event_1(scr_t *scr, ship_t *ship)
{
    const char story[] = "An asteroid aproches the ship";
    const char *tab[] = {"Try to avoid", "Face it", "Shield up"};

    mvwprintw(scr->event, 1, 1, story);
    print_ship(scr->event, (coord_t){5, 20});
    wrefresh(scr->event);
    switch(button(scr->cmd, tab)) {
    case (0): return(0);
    case (1):
        if (rand()%4 <= 1)
            mvwprintw(scr->event, 3, 1, "The ship succesfully avoid the obstacle");
        else {
            mvwprintw(scr->event, 3, 1, "The ship go it by the rock");
            damage_ship(ship, rand()%10, rand()%8);
        }
        break;
    case (2):
        if (rand()%6 == 1)
            mvwprintw(scr->event, 3, 1, "The rock turn to dust at the contact of the ship");
        else {
            mvwprintw(scr->event, 3, 2, "The rock it the ship, damaging it");
            damage_ship(ship, rand()%20, rand()%8);
        }
        break;
    case (3):
        if (rand()%3 <= 2)
            mvwprintw(scr->event, 3, 1, "The shield succesfully resist the impact");
        else {
            mvwprintw(scr->event, 3, 1, "The rock passes trough the shield, and hit the ship");
            damage_ship(ship, rand()%5, rand()%8);
        }
    }
    return (0);
}
