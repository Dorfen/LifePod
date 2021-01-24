#include "Window.hpp"

Window::Window() {}

Window::Window(const WinStyle &style): _style(style)
{
    win = std::shared_ptr<WINDOW>(::newwin(style.y, style.x, style.off_y, style.off_x),
                                  delwin);
    if (style.is_box == true) box(false);
    if (style.as_title == true) title(false);
}

Window::~Window() {}

void Window::setStyle(const WinStyle style) { _style = style; }

Window::WinStyle Window::getStyle() const { return _style; }

void Window::clear(const bool r)
{
    ::wclear(win.get());
    if (r == true) this->refresh();
}

void Window::box(const bool r)
{
    if (_style.is_box) {
        ::box(win.get(), _style.rs, _style.ts);
        if (r == true) this->refresh();
    }
}

void Window::title(const bool r)
{
    if (_style.as_title) {
        mvwprintw(win.get(), 0, 1, _style.title.c_str());
        if (r == true) this->refresh();
    }
}

void Window::print(const int y, const int x, const std::string str, ...)
{
    va_list args;
    va_start(args, str);
    wmove(win.get(), y, x);
    vw_printw(win.get(), str.c_str(), args);
}

void Window::refresh() { ::wrefresh(win.get()); }
