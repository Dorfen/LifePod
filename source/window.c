/*
** PROJECT, 2019
** LifePos
** File description:
** window
*/

#include "lifepod.h"

scr_t *build_scr_t(void)
{
    scr_t *screen = malloc(sizeof(scr_t));

    screen->event = subwin(stdscr, 6*LINES / 8, 3 * COLS/4, 0, 0);
    wbrefresh(screen->event, ACS_VLINE, ACS_HLINE);
    screen->cmd = subwin(stdscr, 2*LINES/8, 3*COLS/4, 6*LINES/8, 0);
    wbrefresh(screen->cmd, ACS_VLINE, ACS_HLINE);
    screen->status = subwin(stdscr, LINES, COLS/4, 0, 3*COLS/4);
    wbrefresh(screen->status, ACS_VLINE, ACS_HLINE);
    return(screen);
}
