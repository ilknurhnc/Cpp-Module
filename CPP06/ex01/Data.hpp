#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
    std::string content;
    int     id;
    float   value;

    Data(int i, const std::string& c, float v) : id(i), content(c), value(v) {}
};

#endif