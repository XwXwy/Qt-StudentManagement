#ifndef STULIST_H
#define STULIST_H


#include "student.h"

class StuList
{
public:
    ~StuList();
    static std::vector<Student>* get();


private:
    StuList();
    static std::vector<Student>* stulist;
};

#endif // STULIST_H
