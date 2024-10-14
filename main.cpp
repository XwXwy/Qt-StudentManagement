#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include <fstream>


using namespace std;
int main(int argc, char *argv[])
{



    QApplication a(argc, argv);


    MainWindow b;
    b.show();

    return a.exec();





}
