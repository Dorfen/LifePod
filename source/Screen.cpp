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
