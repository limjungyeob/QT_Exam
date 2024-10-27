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
    //Employee 구조체 셍성.
    typedef struct _tEmployee {
        int num;
        QString name;
        QString part;
    } tEmployee;

    QList<tEmployee> m_emplployeeList;

private:
    Ui::Widget *ui;
//slot 함수 저장 출력 생성
private slots:
    void slot_pbtSave();
    void slot_pbtPrint();
};
#endif // WIDGET_H
