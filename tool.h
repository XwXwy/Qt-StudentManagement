#ifndef TOOL_H
#define TOOL_H


#include "student.h"
#include <vector>
class Tool
{
public:
    Tool();
    static void loadAllStudents(std::vector<Student> *stulist,std::string filePath);

    static void writeAllStudents(std::vector<Student> *stulist,std::string filePath);
};

#endif // TOOL_H
