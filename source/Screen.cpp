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

void Screen::refreshW(const ScreenType type)
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

void Screen::titleW(const bool r)
{
    mvwprintw(event_, 0, 1, "Event");
    mvwprintw(cmd_, 0, 1, "Command");
    mvwprintw(status_, 0, 1, "Status");
    if (r == true)
        refreshW();
}

void Screen::titleW(const ScreenType type, const bool r)
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

void Screen::boxW(const bool r)
{
    box(event_, ACS_VLINE, ACS_HLINE);
    box(cmd_, ACS_VLINE, ACS_HLINE);
    box(status_, ACS_VLINE, ACS_HLINE);
    if (r == true)
        refreshW();
}

void Screen::boxW(const ScreenType type, bool r)
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

void Screen::displayShipStatus(const Ship &s, const bool r)
{
    mvwprintw(status_, 2, 1, "Colon :");
    printLoadbar(ScreenType::Status, Coord(3, 1), s.getColon(), 1000);
    mvwprintw(status_, 4, 1, "%04i | 1000", s.getColon());
    mvwprintw(status_, 6, 1, "Landing :");
    printLoadbar(ScreenType::Status, Coord(7, 1), s.getColon(), 1000);
    mvwprintw(status_, 8, 1, "%03i | 100", s.getLanding());
    mvwprintw(status_, 10, 1, "Building :");
    printLoadbar(ScreenType::Status, Coord(11, 1), s.getColon(), 1000);
    mvwprintw(status_, 12, 1, "%03i | 100", s.getBuild());
    mvwprintw(status_, 14, 1, "Athmosphere :");
    printLoadbar(ScreenType::Status, Coord(15, 1), s.getColon(), 1000);
    mvwprintw(status_, 16, 1, "%03i | 100", s.getAtm());
    mvwprintw(status_, 18, 1, "Gravity :");
    printLoadbar(ScreenType::Status, Coord(19, 1), s.getColon(), 1000);
    mvwprintw(status_, 20, 1, "%03i | 100", s.getGrav());
    mvwprintw(status_, 22, 1, "Temperature :");
    printLoadbar(ScreenType::Status, Coord(23, 1), s.getColon(), 1000);
    mvwprintw(status_, 24, 1, "%03i | 100", s.getTemp());
    mvwprintw(status_, 26, 1, "Water :");
    printLoadbar(ScreenType::Status, Coord(27, 1), s.getColon(), 1000);
    mvwprintw(status_, 28, 1, "%03i | 100", s.getWater());
    mvwprintw(status_, 30, 1, "Ressources :");
    printLoadbar(ScreenType::Status, Coord(31, 1), s.getColon(), 1000);
    mvwprintw(status_, 32, 1, "%03i | 100", s.getRes());
    if (r == true)
        refreshW(ScreenType::Status);
}

void Screen::initScreen()
{
    initscr();
    noecho();
    curs_set(false);
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

WINDOW *Screen::getWindow(const ScreenType type)
{
        switch (type) {
            case (ScreenType::Event): return event_; break;
            case (ScreenType::Cmd): return cmd_; break;
            case (ScreenType::Status): return status_; break;
            default: throw std::runtime_error("Not a valid Window"); break;
        }
        return (nullptr);
}

void Screen::printLoadbar(const ScreenType type, const Coord coord, \
                          const int value, const int max, const bool r)
{
    WINDOW *win = getWindow(type);
    const int bar_size = getmaxx(win) - 4;
    const int coord_ = (value * bar_size) / max;
    std::string bar;

    bar.resize(bar_size + 1);
    bar[bar_size] = '\0';
    for (int i = 0; i < bar_size; i++)
        bar[i] = '-';
    for (int i = 0; i <= coord_ && bar[i] != '\0'; i++)
        bar[i] = '#';
    mvwprintw(win, coord.y, coord.x, "[%s]", bar.c_str());
    if (r == true)
        refreshW(type);
}

void Screen::displayEventTxt(const std::vector<std::string> &e, const bool r)
{
    for (long unsigned int i = 1; i - 1 < e.size(); i++) {
        mvwprintw(event_, i + 1, 2, e.at(i - 1).c_str());
    }
    if (r == true)
        refreshW(ScreenType::Event);
}

Screen::Coord::Coord(const int y_, const int x_) :
    y(y_),
    x(x_)
{}
