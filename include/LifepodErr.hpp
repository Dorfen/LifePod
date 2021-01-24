#include <string>

#ifndef _LIFEPODERR_HPP_
#define _LIFEPODERR_HPP_

class LifepodErr : public std::exception
{
public:
    LifepodErr(const std::string &message);
    const std::string getMessage() const;

private:
    std::string _message;
};

#endif    //_LIFEPODERR_HPP_
