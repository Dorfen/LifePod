#include "Window.hpp"

Window::Window() : _win(nullptr)
{}

Window::Window(const WinStyle &style) :
    _style(style)
{
    _win = newwin(style.y, style.x, style.off_y, style.off_x);
    if (style.is_box == true)
        box(false);
    if (style.is_title == true)
        title(false);
}

Window::~Window()
{
    delwin(_win);
}

void Window::setStyle(const WinStyle style)
{
    _style = style;
}

Window::WinStyle Window::getStyle()const
{
    return _style;
}

WINDOW *Window::getWindow()
{
    return _win;
}

void Window::clear(const bool r)
{
    wclear(_win);
    if (r == true)
        this->refresh();
}

void Window::box(const bool r)
{
    if (_style.is_box) {
        ::box(_win, _style.rs, _style.ts);
        if (r == true)
            this->refresh();
    } else
        throw WindowErr("No Box");
}

void Window::title(const bool r)
{
    if (_style.is_title) {
        mvwprintw(_win, 0, 1, _style.title.c_str());
        if (r == true)
            this->refresh();
    } else
        throw WindowErr("No title");
}

void Window::print(const int y, const int x, const std::string &str, ...)
{
    va_list args;
    va_start(args, str);
    wmove(_win, y, x);
    vw_printw(_win, str.c_str(), args);
}

void Window::refresh()
{
    wrefresh(_win);
}
