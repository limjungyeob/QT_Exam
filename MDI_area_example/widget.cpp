#include "widget.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QPushButton>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(600,400);
    QMdiArea *area = new QMdiArea();
    area -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);  //���� ���� ũ�� ���� �þ��� �ڵ�
    ////MdiArea�� ���� ���� ����


    //Sub���ٰ� ������ �־���.
    QMdiSubWindow *subWindow1 = new QMdiSubWindow();
    subWindow1 -> resize(300,200);

    QPushButton *btn = new QPushButton("버튼");
    subWindow1->setWidget(btn); //��ư�� subWindow�� ���

    QMdiSubWindow *subWindow2 = new QMdiSubWindow();
    subWindow2->resize(300,200);    //�ι�° subWindow�� �ƹ��͵� ��Ͼ���.

    area->addSubWindow(subWindow1);
    area->addSubWindow(subWindow2);
    //subWindow1,2�� area�� ���.
    QHBoxLayout *hLay  = new QHBoxLayout(); // horizontal Layout ����.

    hLay -> addWidget(area);    //MdiArea ���.

    setLayout(hLay);
}

Widget::~Widget() {

}
