#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

signals:
    void sig_textChanged(QString str); //라인 에디터에 쓰이는 시그널

private slots :
    void slot_valueChanged(int val);    //슬롯 slot_textChanged랑 연결
    void slot_textChanged(QString str); //시그널 sig_textChanged랑 연결
};
#endif // WIDGET_H
