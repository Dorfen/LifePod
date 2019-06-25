/*
** PROJECT, 2019
** my_curse
** File description:
** reshech box
*/

#include "my_curse.h"

int wbrefresh(WINDOW *win, chtype verch, chtype horch)
{
    wclear(win);
    box(win, verch, horch);
    wrefresh(win);
    return (0);
}
