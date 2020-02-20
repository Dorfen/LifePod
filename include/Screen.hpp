#include <ncurses.h>
#include <vector>
#include <string>
#include <stdexcept>

#ifndef _SCREEN_HPP_
#define _SCREEN_HPP_

#include "Ship.hpp"

class Event;

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
        WINDOW *getWindow(const ScreenType type);
        // Print a load bar
        void printLoadbar(const ScreenType type, const Coord coord, \
                          const int value, const int max, const bool r = false);

        // ask for a str in _cmd
        std::string getPromptInput();
        // add a line to the prompt
        void addToPrompt(const std::string &str, bool r = false);
        // print prompt
        void printPrompt(bool r = true);

    public:
        static void initScreen();

    private:
        WINDOW *event_ = nullptr;
        WINDOW *cmd_ = nullptr;
        WINDOW *status_ = nullptr;
        long unsigned int _prompt_size = 0;
        std::vector<std::string> _prompt_history;
};

class ScreenErr: public std::exception
{
    public:
        ScreenErr(const std::string &message);
        const std::string getMessage()const;

    private:
        std::string _message;
};

#endif //_SCREEN_HPP_
