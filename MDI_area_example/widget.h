#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
