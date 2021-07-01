#ifndef H_INFO
#define H_INFO

#include <string>

struct info {
    int id;
    std::string first_name;
    std::string last_name;
    std::string spy_agency;
    std::string city;
    std::string state;
    std::string born_year;
    std::string death_age;
    std::string notes;
    info *child;
    info *prev;
    info *next;
};

#endif
