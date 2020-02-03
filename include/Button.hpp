#include <string>

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

class Button {
    public:
        Button(short system, int dmg, int mult, std::string &msg);
        ~Button();
        short getSystem()const;
        int getDmg()const;
        int getMult()const;
        const std::string &getMsg()const;

    private:
        const short system_;
        const int dmg_;
        const int mult_;
        const std::string msg_;
};

#endif //BUTTON_HPP_
