#include <ncurses.h>
#include <vector>
#include <string>

#include "Ship.hpp"
#include "Event.hpp"

#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_

class Screen
{
    public:
        enum ScreenType {
            Event,
            Cmd,
            Status,
        };
        class Coord {
            public:
                Coord(const int y_, const int x_);
                int y;
                int x;
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
        // Print the ship art
        void printShip(const bool r = true);
        // display Ship Status
        void displayShipStatus(const Ship &s, const bool r = true);
        // print the text of the event
        void displayEventTxt(const std::vector<std::string> &e, const bool r = true);
        // Init the ncurses screen
        WINDOW *getWindow(const ScreenType type);
        // Print a load bar
        void printLoadbar(const ScreenType type, const Coord coord, \
                          const int value, const int max, const bool r = false);
        static void initScreen();

    private:
        WINDOW *event_ = nullptr;
        WINDOW *cmd_ = nullptr;
        WINDOW *status_ = nullptr;
};

class ScreenErr: public std::exception
{
    public:
        ScreenErr(const std::string &message);
        const std::string getMessage()const;

    private:
        std::string _message;
};

#endif //_DISPLAY_HPP_
