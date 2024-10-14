#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
signals:
    void finish();

private slots:
    void on_sureButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
