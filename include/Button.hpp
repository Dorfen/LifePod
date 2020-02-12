#include <string>

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

class Button {
    public:
        Button(short system, int dmg, int mult, std::string &msg);
        Button(std::string str);
        ~Button();
        short getSystem()const;
        int getDmg()const;
        int getMult()const;
        std::string getMsg()const;

    private:
        short system_;
        int dmg_;
        int mult_;
        std::string msg_;
};

class ButtonErr: public std::exception
{
    public:
        ButtonErr(const std::string &message);
        const std::string getMessage()const;

    private:
        const std::string _message;
};

#endif //BUTTON_HPP_
