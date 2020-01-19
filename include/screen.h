/*
** PROJECT, 2020
** LifePod
** File description:
** include/screen.h
*/

#include <ncurses.h>
#include <stdlib.h>

#ifndef SCREEN_H_
#define SCREEN_H_

typedef struct scr_s {
    WINDOW *event;
    WINDOW *cmd;
    WINDOW *status;
    void (* rebox_scr)(struct scr_s *scr);
} scr_t;

scr_t *new_scr(void);

#endif /* SCREEN_H_ */

