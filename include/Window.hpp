#include <ncurses.h>
#include <string>

#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

class Window
{
    public:
        struct WinStyle {
            int y = 0;
            int x = 0;
            int off_y = 0;
            int off_x = 0;
            bool is_box = false;
            chtype rs = ACS_VLINE;
            chtype ts = ACS_HLINE;
            bool is_title = false;
            std::string title;
        };

    public:
        Window();
        Window(const WinStyle &style);
        ~Window();
        void setStyle(const WinStyle style);
        WinStyle getStyle()const;
        WINDOW *getWindow();
        void clear(const bool r = true);
        void box(const bool r = true);
        void title(const bool r = true);
        void refresh();

    protected:
        WinStyle _style;
        WINDOW *_win = nullptr;
};

class WindowErr: public std::exception
{
    public:
        WindowErr(const std::string &msg) : _msg(msg) {};
        const std::string &getMessage()const { return _msg; };

    private:
        const std::string _msg;
};

#endif /*_WINDOW_HPP_*/
