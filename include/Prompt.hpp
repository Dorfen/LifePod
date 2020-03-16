#include <vector>
#include <string>
#include <ncurses.h>

#ifndef _PROMPT_HPP_
#define _PROMPT_HPP_

#include "Window.hpp"

class Prompt: public Window
{
    public:
        Prompt();
        Prompt(const WinStyle &style);
        ~Prompt();
        // ask for a str
        std::string getPromptInput();
        // add a line to the prompt
        void addToPrompt(const std::string &str, const bool r = false);
        // print prompt
        void printPrompt(const bool r = true);
        Prompt &operator<<(const std::string &str);
        void operator>>(std::string &str);

    private:
        long unsigned int _prompt_size = 0;
        std::vector<std::string> _prompt_history;
};

#endif //_PROMPT_HPP_
