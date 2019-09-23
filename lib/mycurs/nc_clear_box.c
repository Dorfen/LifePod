/*
** PROJECT, 2019
** my_curse
** File description:
** reshech box
*/

#include "my_curse.h"

void clear_box(WINDOW *win, chtype verch, chtype horch)
{
    wclear(win);
    box(win, verch, horch);
}
