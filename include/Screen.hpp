#include <ncurses.h>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>

#ifndef _SCREEN_HPP_
#define _SCREEN_HPP_

#include "Ship.hpp"
#include "Window.hpp"
#include "Prompt.hpp"
#include "LifepodErr.hpp"

class Screen
{
    public:
        enum ScreenType {
            Event,
            Cmd,
            Status,
        };
        // Constructor
        Screen();
        // Destructor
        ~Screen();
        // Refresh all the WINDOWs
        void refreshW();
        // Refresh the selected WINDOW
        void refreshW(const ScreenType type);
        // Prit the title of all the WINDOWs
        void titleW(const bool r = true);
        // Prit the title of the selected WINDOW
        void titleW(const ScreenType type, const bool r = true);
        // Box all the WINDOWs
        void boxW(const bool r = true);
        // Box the selected WINDOW
        void boxW(const ScreenType type, const bool r = true);
        // clear all the WINDOWs
        void clearW(const bool r = true);
        // clear the selected WINDOW
        void clearW(const ScreenType type, const bool r = true);
        // Print the ship art
        void printShip(const bool r = true);
        // display Ship Status
        void displayShipStatus(const Ship &s, const bool r = true);
        // print the text of the event
        void displayEventTxt(const std::vector<std::string> &e, const bool r = true);
        // Init the ncurses screen
        Window &getWindow(const ScreenType type);
        // Print a load bar
        void printLoadbar(const ScreenType type, const std::pair<int, int> coord, \
                          const int value, const int max, const bool r = false);


    public:
        static void initScreen();

    public:
        Window event_;
        Prompt cmd_;
        Window status_;
};

class ScreenErr: public LifepodErr
{
    public:
        ScreenErr(const std::string &msg) : LifepodErr(msg) {}
};

#endif //_SCREEN_HPP_
