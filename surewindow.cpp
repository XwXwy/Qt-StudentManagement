#include "surewindow.h"
#include "ui_surewindow.h"

SureWindow::SureWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SureWindow)
{
    ui->setupUi(this);
}

SureWindow::~SureWindow()
{
    delete ui;
}

void SureWindow::on_pushButton_2_clicked()
{

}

