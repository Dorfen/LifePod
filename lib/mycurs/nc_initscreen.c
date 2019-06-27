/*
** PROJECT, 2019
** my_curse
** File description:
** init screen setup terminal
*/

#include "my_curse.h"

static int setup_terminal(struct termios *caps)
{
    caps->c_lflag &= ~ICANON;
    caps->c_cc[VMIN] = 1;
    caps->c_cc[VTIME] = 0;
    if (tcsetattr(0, 0, caps) == -1)
        return (1);
    return (0);
}

int init_screen(void)
{
    struct termios caps;

    tcgetattr(0, &caps);
    if (setup_terminal(&caps) == 1)
        return (-1);
    initscr();
    noecho();
    curs_set(false);
    clear();
    cbreak();
    keypad(stdscr, true);
    refresh();
    return (0);
}
