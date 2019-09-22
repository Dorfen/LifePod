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
#include "parser.h"
#include "my.h"
#include "macros.h"

#ifndef LIFEPOD_H_
#define LIFEPOD_H_

#define EVENT_DIR "./event_data/"

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

int game(scr_t *scr, ship_t *ship, event_t **event);

void refresh_all(scr_t *scr);
void title_win(scr_t *scr);
void display_ship_status(WINDOW *scr, ship_t *ship);

void print_ship(WINDOW *win, int const y, int const x);

event_t *parse_event(char const *buffer);
event_t **load_all_event(void);

void free_event(event_t **event);

int event_related(WINDOW *win, event_t **event);

#endif /*LIFEPOD_H_*/
