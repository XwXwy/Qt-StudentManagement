#ifndef SUREWINDOW_H
#define SUREWINDOW_H

#include <QDialog>

namespace Ui {
class SureWindow;
}

class SureWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SureWindow(QWidget *parent = nullptr);
    ~SureWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::SureWindow *ui;
};

#endif // SUREWINDOW_H
