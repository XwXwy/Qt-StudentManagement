#ifndef STUINFORMATION_H
#define STUINFORMATION_H

#include "student.h"
#include <QWidget>

namespace Ui {
class StuInformation;
}

class StuInformation : public QWidget
{
    Q_OBJECT

public:
    explicit StuInformation(QWidget *parent = nullptr,Student *stu=nullptr);
    ~StuInformation();

private slots:
    void on_returnButton_3_clicked();

    void on_changeButton_clicked();

    void on_deleteButton_2_clicked();

private:
    Student* thisStu;
    Ui::StuInformation *ui;
};

#endif // STUINFORMATION_H
