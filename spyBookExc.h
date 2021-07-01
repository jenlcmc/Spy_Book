#ifndef H_SPYBOOK_EXC
#define H_SPYBOOK_EXC

#include <stdexcept>

// define exception class 
class spyBookExc : public std::runtime_error{
    public:
        spyBookExc(const std::string& data) : std::runtime_error(data){}
};

#endif
