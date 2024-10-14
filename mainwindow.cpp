#include "mainwindow.h"
#include "stuinformation.h"
#include "stulist.h"
#include "ui_mainwindow.h"
#include "tool.h"
#include "widget.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("学生管理系统-20226690-孙博文");
    StuList::get()->clear();
    Tool::loadAllStudents(StuList::get(),"..\\students.txt");//载入学生信息进单例vector

    iniTable(StuList::get()->size(),6);//初始化表格

    showList(StuList::get());//展示学生信息
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniTable(int row,int column){
    ui->tableWidget->resizeRowsToContents();
    QStringList header;
    header<<"学号"<<"姓名"<<"年级"<<"语文成绩"<<"数学成绩"<<"英语成绩"<<"是否选择";
    ui->tableWidget->setColumnCount(header.size());
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(6,QHeaderView::ResizeToContents);


    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止操作表中内容
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置点击表格为选中一行
    ui->lineEdit->setPlaceholderText("请输入学号查找学生");//为搜索框预置提示语

    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

}

void MainWindow::showList(std::vector<Student>* stulist){

    int row=0;



    for(Student &stu:*stulist){

        ui->tableWidget->setItem(row,0,new QTableWidgetItem(stu.getNum()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(stu.getName()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(stu.getGrade()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(stu.getChinese()));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(stu.getMaths()));
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(stu.getEnglish()));

        QTableWidgetItem *check = new QTableWidgetItem();
        check->setCheckState(Qt::Unchecked);
        ui->tableWidget->setItem(row,6,check);
        row++;

    }
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{

}


void MainWindow::on_addButton_2_clicked()
{

    this->close();
    Widget* w=new Widget;
    w->show();



}//添加功能


void MainWindow::on_searchButton_clicked()
{
    QString searchNum=ui->lineEdit->text();

    int flag=0;

    Student *searchStu;
    for(Student &stu:*StuList::get()) {
        if(stu.getNum().compare(searchNum)==0){

            searchStu = &stu;
            StuInformation *si=new StuInformation(nullptr,searchStu);

            si->show();
            this->close();
            flag=1;
            break;
        }
    }


    if(flag==0){
        QMessageBox::warning(this,"提示","没有您查找的学号！");
    }
}//搜索功能


void MainWindow::on_deleteButton_4_clicked()
{

    int flag=0;

    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        if(ui->tableWidget->item(i,6)->checkState()){

            std::vector<Student>::iterator it = StuList::get()->begin();
            StuList::get()->erase(it+i);
            it--;
            ui->tableWidget->removeRow(i);
            i--;
            flag=1;
        }
    }

    if(flag==0){
        QMessageBox::warning(this,"提示","请选择删除的学生信息！");
    }else{
        Tool::writeAllStudents(StuList::get(),"..\\students.txt");
    }


}//删除功能


void MainWindow::on_changeButton_3_clicked()
{
    QString num;

    int flag=0;

    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        if(ui->tableWidget->item(i,6)->checkState()){

            flag++;
            num=ui->tableWidget->item(i,0)->text();
        }
    }


    if(flag>1){
        QMessageBox::warning(this,"提示","请选择一个学生信息修改！");
    }else if(flag==0){
        QMessageBox::warning(this,"提示","请选择修改的学生信息！");
    }else{
        Student *chooseStu;
        for(Student &stu:*StuList::get()) {
            if(stu.getNum().compare(num)==0){

                chooseStu = &stu;
                StuInformation *si=new StuInformation(nullptr,chooseStu);

                si->show();
                this->close();

                break;
            }
        }
    }


}//修改功能

