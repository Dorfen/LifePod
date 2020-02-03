#include <ncurses.h>
#include <memory>
#include <string>

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
        // Constructor
        Screen();
        // Destructor
        ~Screen();
        // Refresh all the WINDOWs
        void refreshW();
        // Refresh the selected WINDOW
        void refreshW(ScreenType type);
        // Prit the title of all the WINDOWs
        void titleW(bool r = true);
        // Prit the title of the selected WINDOW
        void titleW(ScreenType type, bool r = true);
        // Box all the WINDOWs
        void boxW(bool r = true);
        // Box the selected WINDOW
        void boxW(ScreenType type, bool r = true);
        // Init the ncurses screen
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
