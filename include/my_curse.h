/*
** EPITECH PROJECT, 2019
** my_curse lib
** File description:
** header file
*/

#include "my.h"
#include <ncurses.h>
#include <termios.h>

#ifndef MY_CURS_H_
#define MY_CURS_H_

#define PAIR_DEF 0
#define PAIR_ARRAY 9

typedef struct coord_s {
    int x;
    int y;
} coord_t;

int init_screen(void);
int nc_put_str_array(WINDOW *win, char **tab, int color);
int wbrefresh(WINDOW *win, chtype verch, chtype horch);
int nc_strarr_move(WINDOW *win, char **tab, coord_t *coord, int color);
void load_bar(WINDOW *box, char const *name, coord_t const coord, int value[2]);

#endif
