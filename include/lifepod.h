/*
** PROJECT, 2019
** lifepod
** File description:
** header
*/

#define _GNU_SOURCE
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "my_curse.h"
#include "my.h"
#include "macros.h"

#ifndef LIFEPOD_H_
#define LIFEPOD_H_

typedef struct scr_s {
    WINDOW *event;
    WINDOW *cmd;
    WINDOW *status;
} scr_t;

typedef struct event_s {
    short system;
    unsigned int dmg;
    unsigned int max_mult;
    char *msg;
} event_t;

typedef struct scan_s {
    unsigned int atm;
    unsigned int grav;
    unsigned int temp;
    unsigned int water;
    unsigned int res;
} scan_t;

typedef struct ship_s {
    unsigned int colon;
    scan_t *scan;
    unsigned int landing;
    unsigned int build;
} ship_t;

scan_t *alloc_scan(void);
ship_t *alloc_ship(void);
event_t *alloc_event(void);
scr_t *build_scr_t(void);

int game(ship_t *ship);

int display_ship_status(WINDOW *scr, ship_t *ship);

void print_ship(WINDOW *win, coord_t const coord);

event_t **load_all_event(void);

#endif /*LIFEPOD_H_*/
