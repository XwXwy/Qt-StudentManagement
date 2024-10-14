 #include "stuinformation.h"
#include "mainwindow.h"
#include "student.h"
#include "surewindow.h"
#include "ui_stuinformation.h"
#include <QMessageBox>
#include "stulist.h"
#include "tool.h"
StuInformation::StuInformation(QWidget *parent,Student *stu) :
    QWidget(parent),
    ui(new Ui::StuInformation)
{

    thisStu=stu;
    ui->setupUi(this);
    ui->label_name->setText(stu->getName());
    ui->label_num->setText(stu->getNum());
    ui->label_grade->setText(stu->getGrade());
    ui->lineEdit->setText(stu->getChinese());
    ui->lineEdit_2->setText(stu->getMaths());
    ui->lineEdit_3->setText(stu->getEnglish());
}

StuInformation::~StuInformation()
{

    delete ui;
}

void StuInformation::on_returnButton_3_clicked()
{
    this->close();
    MainWindow* m = new MainWindow;
    m->show();
}


void StuInformation::on_changeButton_clicked()
{
    SureWindow s;
    if(s.exec()==QDialog::Accepted){
        QString chinese = ui->lineEdit->text();
        QString mathe = ui->lineEdit_2->text();
        QString eng = ui->lineEdit_3->text();


        for(Student &stu:*StuList::get()) {
            if(stu.getNum().compare(thisStu->getNum())==0){
                stu.setChinese(chinese);
                stu.setMaths(mathe);
                stu.setEnglish(eng);
                Tool::writeAllStudents(StuList::get(),"..\\students.txt");
            }
        }

        QMessageBox::warning(this,"提示","修改成功！");
    }else{


    }
}


void StuInformation::on_deleteButton_2_clicked()
{
    SureWindow s;
    if(s.exec()==QDialog::Accepted){


        int flag=0;
        for(Student &stu:*StuList::get()) {
            if(stu.getNum().compare(thisStu->getNum())==0){

                std::vector<Student>::iterator it = StuList::get()->begin();
                StuList::get()->erase(it+flag);
                Tool::writeAllStudents(StuList::get(),"..\\students.txt");
                QMessageBox::warning(this,"提示","删除成功！");
                this->close();
                MainWindow* m = new MainWindow;
                m->show();
                break;
            }
            flag++;
        }


    }else{


    }
}

