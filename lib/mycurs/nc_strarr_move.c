/*
** PROJECT, 2019
** mycurs
** File description:
** nc_strarr_move
*/

#include "my_curse.h"

int nc_strarr_move(WINDOW *win, char **tab, coord_t *coord, int color)
{
    clear_box(win, ACS_VLINE, ACS_HLINE);
    (color == -1) ? (color = COLOR_WHITE) : (0);
    init_pair(9, color, COLOR_BLACK);
    wattron(win, COLOR_PAIR(9));
    for (int i = 0; tab[i] != NULL; i++) {
        mvwprintw(win, coord->y++, coord->x, tab[i]);
    }
    wattroff(win, COLOR_PAIR(9));
    wrefresh(win);
    return (0);
}
