/*
** PROJECT, 2019
** my_put_array ncurses
** File description:
** i
*/

#include "my_curse.h"

int nc_put_str_array(WINDOW *win, char **tab, int const color)
{
    int lenght = my_tablen(tab);

    wclear(win);
    box(win, ACS_VLINE, ACS_HLINE);
    wrefresh(win);
    init_pair(9, color, COLOR_BLACK);
    wattron(win, COLOR_PAIR(9));
    for (int i = 0; i < lenght; i++) {
        if (tab[i][0] != '\0') {
            mvwprintw(win, i + 2, 2, "%s", tab[i]);
        }
    }
    wattroff(win, COLOR_PAIR(9));
    wrefresh(win);
    return (0);
}
