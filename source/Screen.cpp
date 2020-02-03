#include "Screen.hpp"
#include <curses.h>

Screen::Screen()
{
    Screen::initScreen();
    event_ = subwin(stdscr, 6 * LINES / 8, 3 * COLS / 4, 0, 0);
    cmd_ = subwin(stdscr, 2 * LINES / 8 + 1, 3 * COLS / 4, 6*LINES/8, 0);
    status_ = subwin(stdscr, LINES, COLS / 4, 0, 3 * COLS/4);
    boxW(false);
    titleW(false);
    refreshW();
}

Screen::~Screen()
{
    endwin();
}

void Screen::refreshW()
{
    wrefresh(event_);
    wrefresh(cmd_);
    wrefresh(status_);
}

void Screen::refreshW(ScreenType type)
{
    switch (type) {
    case ScreenType::Event:
        wrefresh(event_);
        break;
    case ScreenType::Cmd:
        wrefresh(cmd_);
        break;
    case ScreenType::Status:
        wrefresh(status_);
        break;
    default:
        throw ScreenErr("Not a valid window");
        break;
    }
}

void Screen::titleW(bool r)
{
    mvwprintw(event_, 0, 1, "Event");
    mvwprintw(cmd_, 0, 1, "Command");
    mvwprintw(status_, 0, 1, "Status");
    if (r == true)
        refreshW();
}

void Screen::titleW(ScreenType type, bool r)
{
    switch (type) {
        case ScreenType::Event: mvwprintw(event_, 0, 1, "Event"); break;
        case ScreenType::Cmd: mvwprintw(cmd_, 0, 1, "Command"); break;
        case ScreenType::Status: mvwprintw(status_, 0, 1, "Status"); break;
        default: throw ScreenErr("Not a valid window"); break;
    }
    if (r == true)
        refreshW(type);
}

void Screen::boxW(bool r)
{
    box(event_, ACS_VLINE, ACS_HLINE);
    box(cmd_, ACS_VLINE, ACS_HLINE);
    box(status_, ACS_VLINE, ACS_HLINE);
    if (r == true)
        refreshW();
}

void Screen::boxW(ScreenType type, bool r)
{
    switch (type) {
        case ScreenType::Event: box(event_, ACS_VLINE, ACS_HLINE); break;
        case ScreenType::Cmd: box(cmd_, ACS_VLINE, ACS_HLINE); break;
        case ScreenType::Status: box(status_, ACS_VLINE, ACS_HLINE); break;
        default: throw ScreenErr("Not a valid window"); break;
    }
    if (r == true)
        refreshW();
}

void Screen::initScreen()
{
    initscr();
    // noecho();
    // curs_set(false);
    clear();
    cbreak();
    keypad(stdscr, true);
}

void Screen::printShip(const bool r)
{
    int x = 0;
    int y = 0;

    getmaxyx(event_, y, x);
    mvwprintw(event_, y - 15, x - 65, "                    `. ___");
    mvwprintw(event_, y - 14, x - 65, "                    __,' __`.                _..----....____");
    mvwprintw(event_, y - 13, x - 65, "        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'");
    mvwprintw(event_, y - 12, x - 65, "  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'");
    mvwprintw(event_, y - 11, x - 65, ",'________________                          \\`-._`-','");
    mvwprintw(event_, y - 10, x - 65, " `._              ```````````------...___   '-.._'-:");
    mvwprintw(event_, y - 9, x - 65, "    ```--.._      ,.                     ````--...__\\-.");
    mvwprintw(event_, y - 8, x - 65, "            `.--. `-`                       ____    |  |`");
    mvwprintw(event_, y - 7, x - 65, "              `. `.                       ,'`````.  ;  ;`");
    mvwprintw(event_, y - 6, x - 65, "                `._`.        __________   `.      \\'__/`");
    mvwprintw(event_, y - 5, x - 65, "                   `-:._____/______/___/____`.     \\  `");
    mvwprintw(event_, y - 4, x - 65, "                              |       `._    `.    \\");
    mvwprintw(event_, y - 3, x - 65, "                               `._________`-.   `.   `.___");
    mvwprintw(event_, y - 2, x - 65, "                                                  `------'`");
    if (r == true)
        refreshW(ScreenType::Event);
}

