#ifndef STUDENT_H
#define STUDENT_H
#include <QString>

class Student
{
public:
    Student(QString name,QString grade,QString num,QString chinese,QString maths,QString english);
    Student();
    ~Student();

    void setName(QString& name);
    void setGrade(QString& grade);
    void setNum(QString& num);
    void setChinese(QString& chinese);
    void setMaths(QString& maths);
    void setEnglish(QString& english);

    QString getName();
    QString getGrade();
    QString getNum();
    QString getChinese();
    QString getMaths();
    QString getEnglish();
private:
    QString name;
    QString grade;
    QString number;
    QString chinese;
    QString maths;
    QString english;
};

#endif // STUDENT_H
