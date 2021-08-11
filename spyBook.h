#include "info.h"

class spyBook{
    info *head;
    info *last;
    info *firstToDisplay;
    void loadFile(std::string); 
    info* parseAllocate(std::string); 
    void addRecord(std::string);
    void displayRecord(info*);
    void displayAll(info*);
    void displayTree(info*, int);
    public:
    spyBook(std::string);
    ~spyBook();
    void display3();
    void goToFirst();
    void display(const char);
    void search();
    void operator++();
    void operator--();
    void add();
};
