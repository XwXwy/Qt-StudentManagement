#include "widget.h"
#include "mainwindow.h"
#include "student.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <fstream>
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_sureButton_clicked()
{
    ofstream fout;
    ifstream fin;
    fout.open("..\\students.txt",ios::app);
    QString newName = ui->nameEdit->text();
    QString newNum = ui->numEdit_2->text();
    QString newGrade = ui->gradeEdit_3->text();
    QString newChinese = ui->chineseEdit_4->text();
    QString newMaths = ui->mathsEdit_5->text();
    QString newEng = ui->englishEdit_6->text();

    if (!newName.isEmpty()&&!newNum.isEmpty()&&!newGrade.isEmpty()&&!newChinese.isEmpty()&&!newMaths.isEmpty()&&!newEng.isEmpty()) {
        Student *newStu = new Student(newName,newGrade,newNum,newChinese,newMaths,newEng);

        fout<<newStu->getName().toStdString()<<" "<<newStu->getNum().toStdString()<<" "
             <<newStu->getGrade().toStdString()<<" "<<newStu->getChinese().toStdString()<<" "
             <<newStu->getMaths().toStdString()<<" "<<newStu->getEnglish().toStdString()<<endl;


        QMessageBox::warning(this,"提示","添加成功！");
        this->close();
        MainWindow* m = new MainWindow;
        m->show();


    }else{
        QMessageBox::warning(this,"提示","请输入完整信息！");
    }
}


void Widget::on_exitButton_clicked()
{

    this->close();
    MainWindow* m = new MainWindow;
    m->show();
}

