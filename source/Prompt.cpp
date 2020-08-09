#include "Prompt.hpp"

Prompt::Prompt() :
    Window()
{}

Prompt::Prompt(const WinStyle &style) :
    Window(style),
    _prompt_size(style.y - 3),
    _prompt_history()
{
    _prompt_history.reserve(_prompt_size);
}

Prompt::~Prompt()
{}

std::string Prompt::getPromptInput()
{
    char msg[COLS];

    echo();
    curs_set(true);
    mvprintw(LINES - 3, 2, "> ");
    getstr(msg);
    noecho();
    curs_set(false);
    if (msg[0] != '\n')
        *this << "> " << msg;
    return std::string(msg);
}

void Prompt::addToPrompt(const std::string &str, const bool r)
{
    if (_prompt_history.size() >= _prompt_size)
        _prompt_history.erase(_prompt_history.begin());
    _prompt_history.push_back(str);
    if (r == true)
        printPrompt();
}

void Prompt::printPrompt(const bool r)
{
    unsigned s = 0;

    this->clear(false);
    this->box(false);
    this->title(false);
    for (auto &i : _prompt_history) {
        this->print(++s, 2, i);
    }
    if (r == true)
        this->refresh();
}

Prompt &Prompt::operator<<(const std::string &str)
{
    this->addToPrompt(str, true);
    return *this;
}

void Prompt::operator>>(std::string &str)
{
    str = getPromptInput();
}
