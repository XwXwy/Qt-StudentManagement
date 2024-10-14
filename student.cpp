#include "student.h"

Student::Student(QString name,QString grade,QString num,QString chinese,QString maths,QString english)
{
    this->name=name;
    this->grade=grade;
    this->number=num;
    this->chinese=chinese;
    this->maths=maths;
    this->english=english;
}

Student::Student(){

}
Student::~Student(){

}

void Student::setName(QString& name){
    this->name=name;
}

void Student::setGrade(QString& grade){
    this->grade=grade;
}

void Student::setNum(QString& num){
    this->number=num;
}

void Student::setChinese(QString& chinese){
    this->chinese=chinese;
}
void Student::setMaths(QString& maths){
    this->maths=maths;
}
void Student::setEnglish(QString& english){
    this->english=english;
}

QString Student::getName(){
    return name;
}

QString Student::getGrade(){
    return grade;
}
QString Student::getNum(){
    return number;
}

QString Student::getChinese(){
    return chinese;
}

QString Student::getMaths(){
    return maths;
}

QString Student::getEnglish(){
    return english;
}
