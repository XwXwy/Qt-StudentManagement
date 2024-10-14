#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "student.h"
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showList(std::vector<Student>* stulist);

private slots:
    void on_tableWidget_cellClicked(int row, int column);

    void on_addButton_2_clicked();

    void on_searchButton_clicked();

    void on_deleteButton_4_clicked();

    void on_changeButton_3_clicked();

private:
    Ui::MainWindow *ui;
    void iniTable(int row,int column);
};

#endif // MAINWINDOW_H
