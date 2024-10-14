#include "qdebug.h"
#include "student.h"
#include "tool.h"
#include <string>
#include <vector>
#include <fstream>
#include<iostream>
#include<QString>
Tool::Tool()
{

}

void Tool::loadAllStudents(std::vector<Student> *stulist,std::string filePath){

    std::ifstream fin;
    fin.open(filePath);
    if(!fin.is_open()){
        std::cout<<"Could not open "<<filePath<<std::endl;
    }

    while(fin.peek()!=EOF){

        std::string tempName;
        std::string tempNum;
        std::string tempGrade;
        std::string tempChinese;
        std::string tempMaths;
        std::string tempEng;

        fin>>tempName>>tempNum>>tempGrade>>tempChinese>>tempMaths>>tempEng;

        fin.ignore(1);
        QString newName=QString::fromStdString(tempName);

        QString newNum=QString::fromStdString(tempNum);
        QString newGrade=QString::fromStdString(tempGrade);
        QString newChinese=QString::fromStdString(tempChinese);
        QString newMaths=QString::fromStdString(tempMaths);
        QString newEng=QString::fromStdString(tempEng);



        Student newStudent(newName,newGrade,newNum,newChinese,newMaths,newEng);
        stulist->push_back(newStudent);


    }
}//从文件中读取所有学生信息 并将其实例化为对象存储进vector中

void Tool::writeAllStudents(std::vector<Student> *stulist,std::string filePath){
    std::ofstream fout;
    fout.open(filePath,std::ios::trunc);

    for(Student &newStu:*stulist) {
        fout<<newStu.getName().toStdString()<<" "<<newStu.getNum().toStdString()<<" "
             <<newStu.getGrade().toStdString()<<" "<<newStu.getChinese().toStdString()<<" "
             <<newStu.getMaths().toStdString()<<" "<<newStu.getEnglish().toStdString()<<std::endl;
    }
}//将学生信息vector写入文件中
