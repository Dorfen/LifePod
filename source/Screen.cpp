#include "Screen.hpp"
#include <curses.h>

Screen::Screen()
{
    Screen::initScreen();
    Window::WinStyle event = { 7 * LINES / 10, 7 * COLS / 10, 0, 0, true, ACS_VLINE, ACS_HLINE, true, "Event"};
    Window::WinStyle cmd = { 3 * LINES /10 + 1, 7 * COLS / 10, 7 * LINES / 10, 0, true, ACS_VLINE, ACS_HLINE, true, "Command"};
    Window::WinStyle status = {LINES, 3 * COLS / 10, 0, 7 * COLS / 10, true, ACS_VLINE, ACS_HLINE, true, "Status"};
    event_ = Window(event);
    cmd_ = Prompt(cmd);
    status_ = Window(status);
    refreshW();
}

Screen::~Screen()
{
    endwin();
}

void Screen::refreshW()
{
    event_.refresh();
    cmd_.refresh();
    status_.refresh();
}

void Screen::refreshW(const ScreenType type)
{
    switch (type) {
    case ScreenType::Event:
        event_.refresh();
        break;
    case ScreenType::Cmd:
        cmd_.refresh();
        break;
    case ScreenType::Status:
        status_.refresh();
        break;
    default:
        throw ScreenErr("Not a valid window");
        break;
    }
}

void Screen::titleW(const bool r)
{
    event_.title(r);
    cmd_.title(r);
    status_.title(r);
}

void Screen::titleW(const ScreenType type, const bool r)
{
    switch (type) {
        case ScreenType::Event: event_.title(r); break;
        case ScreenType::Cmd: cmd_.title(r); break;
        case ScreenType::Status: status_.title(r); break;
        default: throw ScreenErr("Not a valid window"); break;
    }
}

void Screen::boxW(const bool r)
{
    event_.box(r);
    cmd_.box(r);
    status_.box(r);
}

void Screen::boxW(const ScreenType type, const bool r)
{
    switch (type) {
        case ScreenType::Event: event_.box(r); break;
        case ScreenType::Cmd: cmd_.box(r); break;
        case ScreenType::Status: status_.box(r); break;
        default: throw ScreenErr("Not a valid window"); break;
    }
}

void Screen::clearW(const bool r)
{
    event_.clear(r);
    cmd_.clear(r);
    status_.clear(r);
}

void Screen::clearW(const ScreenType type, const bool r)
{
    switch (type) {
        case ScreenType::Event: event_.clear(r); break;
        case ScreenType::Cmd: cmd_.clear(r); break;
        case ScreenType::Status: status_.clear(r); break;
        default: throw ScreenErr("Not a valid window"); break;
    }
    if (r == true)
        refreshW(type);
}

void Screen::displayShipStatus(const Ship &s, const bool r)
{
    mvwprintw(status_.getWindow(), 2, 1, "Colon :");
    printLoadbar(ScreenType::Status, std::pair<int, int>(3, 1), s.getColon(), 1000);
    mvwprintw(status_.getWindow(), 4, 1, "%04i | 1000", s.getColon());
    mvwprintw(status_.getWindow(), 6, 1, "Landing :");
    printLoadbar(ScreenType::Status, std::pair<int, int>(7, 1), s.getLanding(), 100);
    mvwprintw(status_.getWindow(), 8, 1, "%03i | 100", s.getLanding());
    mvwprintw(status_.getWindow(), 10, 1, "Building :");
    printLoadbar(ScreenType::Status, std::pair<int, int>(11, 1), s.getBuild(), 100);
    mvwprintw(status_.getWindow(), 12, 1, "%03i | 100", s.getBuild());
    mvwprintw(status_.getWindow(), 14, 1, "Athmosphere :");
    printLoadbar(ScreenType::Status, std::pair<int, int>(15, 1), s.getAtm(), 100);
    mvwprintw(status_.getWindow(), 16, 1, "%03i | 100", s.getAtm());
    mvwprintw(status_.getWindow(), 18, 1, "Gravity :");
    printLoadbar(ScreenType::Status, std::pair<int, int>(19, 1), s.getGrav(), 100);
    mvwprintw(status_.getWindow(), 20, 1, "%03i | 100", s.getGrav());
    mvwprintw(status_.getWindow(), 22, 1, "Temperature :");
    printLoadbar(ScreenType::Status, std::pair<int, int>(23, 1), s.getTemp(), 100);
    mvwprintw(status_.getWindow(), 24, 1, "%03i | 100", s.getTemp());
    mvwprintw(status_.getWindow(), 26, 1, "Water :");
    printLoadbar(ScreenType::Status, std::pair<int, int>(27, 1), s.getWater(), 100);
    mvwprintw(status_.getWindow(), 28, 1, "%03i | 100", s.getWater());
    mvwprintw(status_.getWindow(), 30, 1, "Ressources :");
    printLoadbar(ScreenType::Status, std::pair<int, int>(31, 1), s.getRes(), 100);
    mvwprintw(status_.getWindow(), 32, 1, "%03i | 100", s.getRes());
    if (r == true)
        refreshW(ScreenType::Status);
}

void Screen::printShip(const bool r)
{
    int x = 0;
    int y = 0;

    getmaxyx(event_.getWindow(), y, x);
    mvwprintw(event_.getWindow(), y - 15, x - 63, "                    `. ___");
    mvwprintw(event_.getWindow(), y - 14, x - 63, "                    __,' __`.                _..----....____");
    mvwprintw(event_.getWindow(), y - 13, x - 63, "        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'");
    mvwprintw(event_.getWindow(), y - 12, x - 63, "  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'");
    mvwprintw(event_.getWindow(), y - 11, x - 63, ",'________________                          \\`-._`-','");
    mvwprintw(event_.getWindow(), y - 10, x - 63, " `._              ```````````------...___   '-.._'-:");
    mvwprintw(event_.getWindow(), y - 9, x - 63, "    ```--.._      ,.                     ````--...__\\-.");
    mvwprintw(event_.getWindow(), y - 8, x - 63, "            `.--. `-`                       ____    |  |`");
    mvwprintw(event_.getWindow(), y - 7, x - 63, "              `. `.                       ,'`````.  ;  ;`");
    mvwprintw(event_.getWindow(), y - 6, x - 63, "                `._`.        __________   `.      \\'__/`");
    mvwprintw(event_.getWindow(), y - 5, x - 63, "                   `-:._____/______/___/____`.     \\  `");
    mvwprintw(event_.getWindow(), y - 4, x - 63, "                              |       `._    `.    \\");
    mvwprintw(event_.getWindow(), y - 3, x - 63, "                               `._________`-.   `.   `.___");
    mvwprintw(event_.getWindow(), y - 2, x - 63, "                                                  `------'`");
    if (r == true)
        refreshW(ScreenType::Event);
}

Window &Screen::getWindow(const ScreenType type)
{
        switch (type) {
            case (ScreenType::Event): return event_; break;
            case (ScreenType::Cmd): return cmd_; break;
            case (ScreenType::Status): return status_; break;
            default: throw std::runtime_error("Not a valid Window"); break;
        }
}

void Screen::printLoadbar(const ScreenType type, const std::pair<int, int> coord, \
                          const int value, const int max, const bool r)
{
    WINDOW *win = getWindow(type).getWindow();
    const int bar_size = getmaxx(win) - 4;
    const int coord_ = (value * bar_size) / max;
    std::string bar;

    bar.resize(bar_size + 1);
    bar[bar_size] = '\0';
    for (int i = 0; i < bar_size; i++)
        bar[i] = '-';
    for (int i = 0; i < coord_ && bar[i] != '\0'; i++)
        bar[i] = '#';
    mvwprintw(win, coord.first, coord.second, "[%s]", bar.c_str());
    if (r == true)
        refreshW(type);
}

void Screen::displayEventTxt(const std::vector<std::string> &e, const bool r)
{
    clearW(ScreenType::Event, false);
    boxW(ScreenType::Event, false);
    titleW(ScreenType::Event, false);
    printShip(false);
    for (long unsigned int i = 1; i - 1 < e.size(); i++) {
        mvwprintw(event_.getWindow(), i + 1, 2, e.at(i - 1).c_str());
    }
    if (r == true)
        refreshW(ScreenType::Event);
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
